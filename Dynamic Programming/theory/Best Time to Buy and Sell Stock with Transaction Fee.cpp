class Solution {
public:
/*time complexity is O(n*2==n)*/
    int dp[50000][2];
    int solve(vector<int>&arr,int fee,int index,int buy) {
        if(index>=arr.size()) {
            return 0;
        }
        if(dp[index][buy]!=-1) {
            return dp[index][buy];
        }
        int b=0,s=0;
        if(buy==0) {
            b=solve(arr,fee,index+1,1)-arr[index];
        }
        else{
            s=solve(arr,fee,index+1,0)+arr[index]-fee;
        }
        int skip=solve(arr,fee,index+1,buy);
        return dp[index][buy]=max(skip,max(s,b)); 

    }

    int tab(vector<int>&arr,int fee) {
        int n=arr.size();
        vector<vector<int>>dp(n+1,vector<int>(2,0));
        for(int index=n-1;index>-1;index--) {
            for(int buy=0;buy<2;buy++) {
                int b=0,s=0;
                if(buy==0) {
                    b=dp[index+1][1]-arr[index];
                }
                else{
                    s=dp[index+1][0]+arr[index]-fee;
                }
                int skip=dp[index+1][buy];
                dp[index][buy]=max(skip,max(s,b));
            }
        }
        return dp[0][0];
    }
    /*space is O(1)*/
    int tabOpti(vector<int>&arr,int fee) {
        int n=arr.size();
        //vector<vector<int>>dp(n+1,vector<int>(2,0));
        vector<int>next(2,0);
        vector<int>curr(2,0);
        for(int index=n-1;index>-1;index--) {
            for(int buy=0;buy<2;buy++) {
                int b=0,s=0;
                if(buy==0) {
                    b=next[1]-arr[index];
                }
                else{
                    s=next[0]+arr[index]-fee;
                }
                int skip=next[buy];
                curr[buy]=max(skip,max(s,b));
            }
            next=curr;
        }
        return next[0];
    }

    int maxProfit(vector<int>& prices, int fee) {
        // memset(dp,-1,sizeof(dp));
        // int ans=solve(prices,fee,0,0);

        int ans=tabOpti(prices,fee);
        return ans;
    }
};