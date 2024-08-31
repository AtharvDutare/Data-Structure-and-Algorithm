class Solution{   
public:
    int n;
    int dp[10001][101];
    int solve(vector<int>&arr,int index,int sum) {
        if(index>=n) {
            if(sum==0) {
                return 1;
            }
            return 0;
        }
        if(dp[sum][index]!=-1) {
            return dp[sum][index];
        }
        bool include=false,exclude=false;
        if(sum-arr[index]>=0) {
            include=solve(arr,index+1,sum-arr[index]);
        }
        exclude=solve(arr,index+1,sum);
        return dp[sum][index]=include||exclude;
    }
    
    int tab(vector<int>&arr,int sums) {
        int n=arr.size();
        vector<vector<int>> dp(sums+1,vector<int>(n+1,0));
        for(int i=0;i<=n;i++) {
            dp[0][i]=1;
        }
        // if(arr[0]<=sums) {
        //     dp[arr[0]][0]=1;
        // }
        for(int index=n-1;index>-1;index--) {
            for(int sum=0;sum<=sums;sum++) {
                 bool include=false,exclude=false;
                if(sum-arr[index]>=0) {
                    include=dp[sum-arr[index]][index+1];
                }
                exclude=dp[sum][index+1];
                dp[sum][index]=include||exclude;
            }
        }
        return dp[sums][0];
    }
    bool isSubsetSum(vector<int>arr, int sum){
        // n=arr.size();
        // memset(dp,-1,sizeof(dp));
        // bool ans=solve(arr,0,sum);
        bool ans=tab(arr,sum);
        return ans;
    }
};