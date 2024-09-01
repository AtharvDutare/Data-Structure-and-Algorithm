class Solution {
public:
    /*time complexity is O(target*n) where n is size of arr
     space is O(n) and recursion stack is O(target)
    */
    int solve(vector<int>&arr,int target,vector<int>&dp) {
        if(target==0) {
            return 0;
        }
        if(target<0) {
            return INT_MAX;
        }
        if(dp[target]!=-1) {
            return dp[target];
        }
        int ans=INT_MAX;
        for(int i=0;i<arr.size();i++) {
            int tempAns=solve(arr,target-arr[i],dp);
            if(tempAns!=INT_MAX) {
                ans=min(ans,1+tempAns);
            }
        }
        return dp[target]=ans;
    }

    int tab(vector<int>&arr,int target) {
        vector<int>dp(target+1,INT_MAX);
        dp[0]=0;
        for(int tar=1;tar<=target;tar++) {
            int ans=INT_MAX;
            for(int i=0;i<arr.size();i++) {
                if(tar-arr[i]>=0) {
                    int tempAns=dp[tar-arr[i]];
                    if(tempAns!=INT_MAX) {
                        ans=min(ans,1+tempAns);
                    }
                }
                
            }
            dp[tar]=ans;
        }
        return dp[target];
    }

    int coinChange(vector<int>& coins, int amount) {
        // vector<int> dp(amount+1,-1);
        // int ans=solve(coins,amount,dp);
        // return ans==INT_MAX?-1:ans;
        int ans=tab(coins,amount);
        return ans==INT_MAX?-1:ans;
    }
};