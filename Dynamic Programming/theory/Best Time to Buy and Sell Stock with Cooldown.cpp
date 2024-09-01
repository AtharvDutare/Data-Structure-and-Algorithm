class Solution {
public:
    /*time complexity is O(N) and O(N)*/
    int dp[5001][2];
    int solve(vector<int>&arr,int index,int buyC) {
        if(index>=arr.size()) {
            return 0;
        }
        if(dp[index][buyC]!=-1) {
            return dp[index][buyC];
        }
        int sell=0;int buy=0;
        if(buyC==0){
            buy=solve(arr,index+1,1)-arr[index];
        }
        else{
            sell=solve(arr,index+2,0)+arr[index];
        }
        int skip=solve(arr,index+1,buyC);
        return dp[index][buyC]=max(skip,max(buy,sell));

    }

    int tab(vector<int>&arr) {
        int n=arr.size();
        vector<vector<int>>dp(n+2,vector<int>(2,0));
        for(int index=n-1;index>-1;index--) {
            for(int buyC=0;buyC<2;buyC++) {
                int sell=0;int buy=0;
                if(buyC==0){
                    buy=dp[index+1][1]-arr[index];
                }
                else{
                    sell=dp[index+2][0]+arr[index];
                }
                int skip=dp[index+1][buyC];
                dp[index][buyC]=max(skip,max(buy,sell));
            }
        }
        return dp[0][0];
    }
    /*space is O(1)*/
    int tabOpti(vector<int>&arr) {
        int n=arr.size();
        //vector<vector<int>>dp(n+2,vector<int>(2,0));
        vector<int>curr(2,0);
        vector<int>next(2,0);
        vector<int>nextNext(2,0);
        for(int index=n-1;index>-1;index--) {
            for(int buyC=0;buyC<2;buyC++) {
                int sell=0;int buy=0;
                if(buyC==0){
                    buy=next[1]-arr[index];
                }
                else{
                    sell=nextNext[0]+arr[index];
                }
                int skip=next[buyC];
                curr[buyC]=max(skip,max(buy,sell));
            }
            nextNext=next;
            next=curr;
        }
        return next[0];
    }

    int maxProfit(vector<int>& prices) {
        // memset(dp,-1,sizeof(dp));
        // int ans=solve(prices,0,0);

        int ans=tabOpti(prices);
        return ans;
    }
};