class Solution {
public:
    /*got memory limit exceeded */
    int solve(vector<int>&arr,int index,int buy,vector<vector<int>>&dp) {
        if(index>=arr.size()) {
            return 0;
        }
        if(dp[index][buy+1]!=-1) {
            return dp[index][buy+1];
        }
        int ans=0;
        if(buy==-1) {
            ans=solve(arr,index+1,arr[index],dp);
        }
        else{
            ans=solve(arr,index+1,-1,dp)+arr[index]-buy;
        }
        int t=solve(arr,index+1,buy,dp);
        return dp[index][buy+1]=max(ans,t);
    }
    /*time complexity is O(N*M)*/
    int solve2(vector<int>&arr,int index,int buy,vector<vector<int>>&dp) {
        if(index>=arr.size()) {
            return 0;
        }
        if(dp[index][buy]!=-1) {
            return dp[index][buy];
        }
        int ans=0;
        if(buy==0) {
            ans=solve2(arr,index+1,1,dp)-arr[index];
        }
        else{
            ans=solve2(arr,index+1,0,dp)+arr[index];
        }
        int t=solve2(arr,index+1,buy,dp);
        return dp[index][buy]=max(ans,t);
    }

    int tab(vector<int>&arr) {
        int n=arr.size();
        vector<vector<int>>dp(n+1,vector<int>(2,0));
        for(int index=n-1;index>-1;index--) {
            for(int buy=0;buy<2;buy++) {
                int ans=0;
                if(buy==0) {
                    ans=dp[index+1][1]-arr[index];
                }
                else{
                    ans=dp[index+1][0]+arr[index];
                }
                int t=dp[index+1][buy];
                dp[index][buy]=max(ans,t);
            }
        }
        return dp[0][0];
    }

    int tabOpti(vector<int>&arr) {
        int n=arr.size();
        //vector<vector<int>>dp(n+1,vector<int>(2,0));
        vector<int>curr(2,0);
        vector<int>next(2,0);
        for(int index=n-1;index>-1;index--) {
            for(int buy=0;buy<2;buy++) {
                int ans=0;
                if(buy==0) {
                    ans=next[1]-arr[index];
                }
                else{
                    ans=next[0]+arr[index];
                }
                int t=next[buy];
                curr[buy]=max(ans,t);
            }
            next=curr;
        }
        return next[0];
    }

    int maxProfit(vector<int>& prices) {
        int n=prices.size();
        //int maxi=*max_element(prices.begin(),prices.end());
        //vector<vector<int>> dp(n,vector<int>(maxi+2,-1));

        // vector<vector<int>> dp(n+1,vector<int>(2,-1));
        // int ans=solve2(prices,0,0,dp);

        int ans=tabOpti(prices);
        return ans; 
    }
};