class Solution {
public:
    int dp[301][301];
    int solve(vector<int>&arr,int i,int j) {
        if(i>j) return 0;
        if(dp[i][j]!=-1) {
            return dp[i][j];
        }
        int ans=INT_MIN;
        for(int k=i;k<=j;k++) {
            int tempAns=arr[i-1]*arr[k]*arr[j+1]+solve(arr,i,k-1)+solve(arr,k+1,j);
            ans=max(tempAns,ans);
        }
        return dp[i][j]=ans;
    }

    int tab(vector<int> &arr,int n) {
        vector<vector<int>>dp(n+2,vector<int>(n+2,0));
        for(int i=n;i>=1;i--) {
            for(int j=i;j<=n;j++) {
                int ans=INT_MIN;
                for(int k=i;k<=j;k++) {
                    int tempAns=arr[i-1]*arr[k]*arr[j+1]+dp[i][k-1]+dp[k+1][j];
                    ans=max(tempAns,ans);
                }
                dp[i][j]=ans;
            }
        }
        return dp[1][n];
    }

    int maxCoins(vector<int>& nums) {
        int n=nums.size();
        nums.push_back(1);
        nums.insert(nums.begin(),1);
        // memset(dp,-1,sizeof(dp));
        // int ans=solve(nums,1,n);
        int ans=tab(nums,n);
        return ans;
    }
};