
class Solution{
public:
    int dp[1001][1001];
    /*time complexity is O(n*w) and space complexity is O(n*w) and recursion stack is O(w)*/
    int solve(int index,int val[],int wt[],int n,int w) {
        if(index>=n) {
            return 0;
        }
        if(dp[index][w]!=-1) {
            return dp[index][w];
        }
        int take=0;
        int not_take=solve(index+1,val,wt,n,w);
        if(w-wt[index]>=0) {
            take=solve(index,val,wt,n,w-wt[index])+val[index];
        }
        return dp[index][w]=max(take,not_take);
    }
    
    int tab(int val[],int wt[],int n,int w) {
        vector<vector<int>> dp(n+1,vector<int>(w+1,0));
        for(int index=n-1;index>-1;index--) {
            for(int wi=1;wi<=w;wi++) {
                int take=0;
                int not_take=dp[index+1][wi];
                if(wi-wt[index]>=0) {
                    take=dp[index][wi-wt[index]]+val[index];
                }
                dp[index][wi]=max(take,not_take);
            }
        }
        return dp[0][w];
    }
    
    int tabOpti(int val[],int wt[],int n,int w) {
        vector<int>curr(w+1,0);
        vector<int> next(w+1,0);
        for(int index=n-1;index>-1;index--) {
            for(int wi=1;wi<=w;wi++) {
                int take=0;
                int not_take=next[wi];
                if(wi-wt[index]>=0) {
                    take=curr[wi-wt[index]]+val[index];
                }
                curr[wi]=max(take,not_take);
            }
            next=curr;
        }
        return curr[w];
    }
    
    
    int knapSack(int N, int W, int val[], int wt[])
    {
        // memset(dp,-1,sizeof(dp));
        // int ans=solve(0,val,wt,N,W);
        // int ans=tab(val,wt,N,W);
        int ans=tabOpti(val,wt,N,W);
        return ans;
    }
};