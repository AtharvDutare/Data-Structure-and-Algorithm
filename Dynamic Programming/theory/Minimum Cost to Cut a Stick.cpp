class Solution {
public:
    int dp[101][101];
    int solve(vector<int>&arr,int i,int j) {
        if(i>j) return 0;
        if(dp[i][j]!=-1) {
            return dp[i][j];
        }

        
        int ans=INT_MAX;
        int cost=arr[j+1]-arr[i-1];
        for(int k=i;k<=j;k++) {
            int tempAns=cost+solve(arr,i,k-1)+solve(arr,k+1,j);
            ans=min(tempAns,ans);
        }
        return dp[i][j]=ans;
    }

    int tab(vector<int> &arr) {
        int n=arr.size();
        vector<vector<int>>dp(n+2,vector<int>(n+2,0));
        for(int i=n-1;i>=1;i--) {
            for(int j=1;j<=n-2;j++) {
                if(i>j) continue;
                int ans=INT_MAX;
                int cost=arr[j+1]-arr[i-1];
                for(int k=i;k<=j;k++) {
                    int tempAns=cost+dp[i][k-1]+dp[k+1][j];
                    ans=min(tempAns,ans);
                }
                dp[i][j]=ans;
            }
        }
        return dp[1][n-2];
    }

    int minCost(int n, vector<int>& cuts) {
        cuts.insert(cuts.begin(),0);
        cuts.push_back(n);
        sort(cuts.begin(),cuts.end());
        // memset(dp,-1,sizeof(dp));
        // int ans=solve(cuts,1,cuts.size()-2);
        int ans=tab(cuts);
        return ans;
    }
};