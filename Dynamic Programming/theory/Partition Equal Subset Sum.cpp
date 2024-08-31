class Solution {
public:
    int n;
    int dp[201][20001];
    int solve(vector<int>& arr,int index,int currSum,int totalSum) {
        if(index>=n) {
            return currSum==totalSum;
        }
        if(currSum==totalSum) {
            return 1;
        }
        if(dp[index][currSum]!=-1) {
            return dp[index][currSum];
        }
        bool include=false;
        if(totalSum>currSum) {
            include=solve(arr,index+1,currSum+arr[index],totalSum-arr[index]);
        }
        bool exclude=solve(arr,index+1,currSum,totalSum);
        return dp[index][currSum]=include||exclude;
    }
    int solve2(vector<int>&arr,int index,int target ){
        if(index>=n) {
            return target==0;
        }
        if(target==0) {
            return 1;
        }
        if(dp[index][target]!=-1){
            return dp[index][target];
        }
        int include=0;
        if(target-arr[index]>=0) {
            include=solve2(arr,index+1,target-arr[index]);
        }
        int exclude=solve2(arr,index+1,target);
        return dp[index][target]=include||exclude;
    }

    int tab(vector<int>&arr) {
        int n=arr.size();
        int totalSum=accumulate(arr.begin(),arr.end(),0);
        if(totalSum%2!=0) {
            return 0;
        }
        int k=totalSum/2;
        vector<vector<int>>dp(n+1,vector<int>(k+1,0));
        for(int i=0;i<=n;i++) {
            dp[i][0]=1;
        }

        for(int index=n-1;index>-1;index--) {
            for(int target=0;target<=k;target++) {
                int include=0,exclude=0;
                if(target-arr[index]>=0) {
                    include=dp[index+1][target-arr[index]];
                }
                exclude=dp[index+1][target];
                dp[index][target]=include||exclude;
            }
        }
        return dp[0][k];
    }
    int tabOpti(vector<int>&arr) {
        int n=arr.size();
        int totalSum=accumulate(arr.begin(),arr.end(),0);
        if(totalSum%2!=0) {
            return 0;
        }
        int k=totalSum/2;
        vector<int> next(k+1,0);
        vector<int> curr(k+1,0);
        for(int i=0;i<=n;i++) {
            next[0]=1;
        }

        for(int index=n-1;index>-1;index--) {
            for(int target=0;target<=k;target++) {
                int include=0,exclude=0;
                if(target-arr[index]>=0) {
                    include=next[target-arr[index]];
                }
                exclude=next[target];
                curr[target]=include||exclude;
            }
            next=curr;
        }
        return next[k];
    }


    bool canPartition(vector<int>& nums) {
        // n=nums.size();
        // int totalSum=accumulate(nums.begin(),nums.end(),0);
        // if(totalSum%2) {
        //     return false;
        // }
        // memset(dp,-1,sizeof(dp));
        // bool ans=solve2(nums,0,totalSum/2);
        int ans=tabOpti(nums);
        return ans;
    }
};