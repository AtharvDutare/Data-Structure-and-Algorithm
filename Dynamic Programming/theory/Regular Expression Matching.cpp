class Solution {
public:
    bool isMatch(string s, string p) {
        int m=s.length();
        int n=p.length();
        s=" "+s;
        p=" "+p;
        vector<vector<int>> dp(m+1,vector<int>(n+1,0));
        dp[0][0]=1;
        for(int i=2;i<=n;i++) {
            if(p[i]=='*') {
                dp[0][i]=dp[0][i-2];
            }
        }
        for(int i=1;i<=m;i++) {
            for(int j=1;j<=n;j++) {
                if(s[i]==p[j]||p[j]=='.') {
                    dp[i][j]=dp[i-1][j-1];
                }
                else if(p[j]=='*') {
                    int t=0;
                    dp[i][j]=(j-2>=0?dp[i][j-2]:false);
                    if(p[j-1]==s[i]||p[j-1]=='.') {
                        dp[i][j]|=dp[i-1][j];
                    }
                }
                else {
                    dp[i][j]=false;
                }
            }
        }
        for(int i=1;i<=m;i++) {
            for(int j=1;j<=n;j++) {
                cout<<dp[i][j]<<" ";
            }cout<<endl;
        }
        return dp[m][n];
    }
};