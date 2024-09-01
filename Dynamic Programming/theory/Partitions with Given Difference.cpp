class Solution {
  public:
    int total;
    int m=1e9+7;
    /*time complexity is O(n*total)*/
    int solve(vector<int>&arr,int n,int d,int index,int sum,vector<vector<int>>&dp) {
        if(index>=n) {
            if((sum)*2-total==d){
                return 1;
            }
            return 0;
        }
        if(dp[index][sum]!=-1) {
            return dp[index][sum];
        }
        int include=0,exclude=0;
        if((sum)*2-total==d){
            include++;
        }
        include=solve(arr,n,d,index+1,sum+arr[index],dp);
        exclude=solve(arr,n,d,index+1,sum,dp);
        return dp[index][sum]=(include+exclude)%m;
    }
    /*tabulation not work */
    int tab(vector<int>&arr,int n,int d) {
        int total=accumulate(arr.begin(),arr.end(),0);
        vector<vector<int>>dp(n+1,vector<int>(total+1,0));
        for(int sum=0;sum<=total;sum++) {
            if((sum)*2-total==d){
                dp[n][sum*2]=1;
            }
        }
                
        for(int index=n-1;index>-1;index--) {
            for(int sum=0;sum<=total-arr[index];sum++) {
                int include=0,exclude=0;
                if((sum)*2-total==d){
                    include++;
                }
                include=dp[index+1][sum+arr[index]];
                exclude=dp[index+1][sum];
                dp[index][sum]=(include+exclude)%m;
            }
        }
        return dp[0][total];
    }
    int countPartitions(int n, int d, vector<int>& arr) {
        total=accumulate(arr.begin(),arr.end(),0);
        vector<vector<int>>dp(n+1,vector<int>(total+1,-1));
        int ans=solve(arr,n,d,0,0,dp);
        //int ans=tab(arr,n,d);
        return ans;
    }
};
