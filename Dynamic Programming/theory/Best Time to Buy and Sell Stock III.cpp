class Solution {
public:
    i/*time complexity is o(N*2*3)==O(N)*/
    int solve(vector<int>&arr,int index,int buy,int limit,vector<vector<vector<int>>>&dp) {
        if(index>=arr.size()){
            return 0;
        }
        if(limit<=0) {
            return 0;
        }
        if(dp[index][buy][limit]!=-1) {
            return dp[index][buy][limit];
        }
        int ans=0;
        if(buy==0) {
            ans=solve(arr,index+1,1,limit,dp)-arr[index];
        }
        else{
            ans=solve(arr,index+1,0,limit-1,dp)+arr[index];
        }
        int t=solve(arr,index+1,buy,limit,dp);
        return dp[index][buy][limit]=max(ans,t);

    }

    int tab(vector<int>&arr) {
        int n=arr.size();
        vector<vector<vector<int>>>dp(n+1,vector<vector<int>>(2,vector<int>(3,0)));
        for(int index=n-1;index>-1;index--) {
            for(int buy=0;buy<2;buy++) {
                for(int limit=1;limit<3;limit++) {
                    int ans=0;
                    if(buy==0) {
                        ans=dp[index+1][1][limit]-arr[index];
                    }
                    else{
                        ans=dp[index+1][0][limit-1]+arr[index];
                    }
                    int t=dp[index+1][buy][limit];
                    dp[index][buy][limit]=max(ans,t);
                }
            }
        }
        return dp[0][0][2];
    }
    /*space is O(1)*/
    int tabOpti(vector<int>&arr) {
        int n=arr.size();
        //vector<vector<vector<int>>>dp(n+1,vector<vector<int>>(2,vector<int>(3,0)));
        vector<vector<int>>next(2,vector<int>(3,0));
        vector<vector<int>>curr(2,vector<int>(3,0));
        for(int index=n-1;index>-1;index--) {
            for(int buy=0;buy<2;buy++) {
                for(int limit=1;limit<3;limit++) {
                    int ans=0;
                    if(buy==0) {
                        ans=next[1][limit]-arr[index];
                    }
                    else{
                        ans=next[0][limit-1]+arr[index];
                    }
                    int t=next[buy][limit];
                    curr[buy][limit]=max(ans,t);
                }
            }
            next=curr;
        }
        return next[0][2];
    }

    int maxProfit(vector<int>& prices) {
        int n=prices.size();
        // vector<vector<vector<int>>>dp(n+1,vector<vector<int>>(2,vector<int>(3,-1)));
        // int ans=solve(prices,0,0,2,dp);

        int ans=tabOpti(prices);
        return ans;

    }
};