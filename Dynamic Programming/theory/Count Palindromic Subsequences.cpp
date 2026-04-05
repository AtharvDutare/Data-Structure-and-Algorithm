class Solution {
  public:
    /*You are required to complete below method */
    int countPS(string &s) {
        // Your code here
        int n=s.length();
        s=" "+s;
        vector<vector<int>> dp(n+1,vector<int>(n+1,0));
        for(int g=1;g<=n;g++) {
            for(int i=1,j=g;j<=n;i++,j++) {
               if(g==1) {
                   dp[i][i]=1;
               }
               else if(g==2) {
                   dp[i][j]=((s[i]==s[j])?3:2);
               }
               else {
                    if(s[i]==s[j]) {
                        dp[i][j]=dp[i][j-1]+dp[i+1][j]+1;
                    }
                    else {
                        dp[i][j]=dp[i][j-1]+dp[i+1][j]-dp[i+1][j-1];
                    }
               }
            }
        }
        return dp[1][n];
    }
};