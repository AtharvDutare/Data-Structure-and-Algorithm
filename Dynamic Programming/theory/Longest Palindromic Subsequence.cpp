class Solution {
public:
    /*approach 1*/
    int dp[1001][1001];
    int solve(string &s,int i,int j) {
        if(i>j||i>=s.length()||j<-1) return 0;
        if(dp[i][j]!=-1) {
            return dp[i][j];
        }
        int ans=0;
        if(s[i]==s[j]) {
            int t=i==j?1:2;
            ans=t+solve(s,i+1,j-1);
        }
        else{
            ans=0+max(solve(s,i+1,j),solve(s,i,j-1));
        }
        return dp[i][j]=ans;
    }
    /*tabulation not work in this code I did index shifting */
    int tab(string &s) {
        int n=s.length();
        vector<vector<int>>dp(n+1,vector<int>(n+2,0));
        for(int i=0;i<n;i++) {
            for(int j=n;j>=i;j--) {
                int ans=0;
                if(s[i]==s[j]) {
                    int t=i==j?1:2;
                    ans=t+dp[i+1][j];
                }
                else{
                    ans=0+max(dp[i+1][j],dp[i][j]);
                }
                dp[i][j+1]=ans;
            }
        }
        int ans=0;
        for(int i=0;i<n+2;i++) {
            ans=max(ans,dp[n][i]);
        }
        return ans;
    }

    int longestPalindromeSubseq(string s) {
        // int n=s.length();
        // memset(dp,-1,sizeof(dp));
        // int ans=solve(s,0,n-1);
        int ans=tab(s);
        return ans;        
    }
};
/*approch 2 is just create and other string of reverse of s and use lis code*/