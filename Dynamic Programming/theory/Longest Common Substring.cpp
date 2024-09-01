class Solution {
  public:
    int m;
    int n;
    int ans;
    int dp[1001][1001];
    /*time complexity is O(n*m) and space is O(n*m)*/
    int solve(string &str1,string &str2,int i,int j) {
        if(i>=m) return 0;
        if(j>=n) return 0;
        if(dp[i][j]!=-1) {
            return dp[i][j];
        }
        int tempAns=0;
        if(str1[i]==str2[j]) {
            tempAns=1+solve(str1,str2,i+1,j+1);
            ans=max(tempAns,ans);
        }
        solve(str1,str2,i+1,j);
        solve(str1,str2,i,j+1);
        return dp[i][j]=tempAns;
    }
    
    int tab(string &s1,string &s2) {
        vector<vector<int>> dp(m+1,vector<int>(n+1,0));
        int ans=0;
        for(int i=m-1;i>-1;i--) {
            for(int j=n-1;j>-1;j--) {
                int tempAns=0;
                if(s1[i]==s2[j]) {
                    tempAns=1+dp[i+1][j+1];
                    ans=max(tempAns,ans);
                }
                dp[i][j]=tempAns;
            }
        }
        return ans;
    }
    
    int tabOpti(string &s1,string &s2) {
        //vector<vector<int>> dp(m+1,vector<int>(n+1,0));
        vector<int>next(n+1,0);
        vector<int>curr(n+1,0);
        int ans=0;
        for(int i=m-1;i>-1;i--) {
            for(int j=n-1;j>-1;j--) {
                int tempAns=0;
                if(s1[i]==s2[j]) {
                    tempAns=1+next[j+1];
                    ans=max(tempAns,ans);
                }
                curr[j]=tempAns;
            }
            next=curr;
        }
        return ans;
    }
    
    
  
    int longestCommonSubstr(string str1, string str2) {
        m=str1.length();
        n=str2.length();
        // ans=0;
        // memset(dp,-1,sizeof(dp));
        // solve(str1,str2,0,0);
        // return tab(str1,str2);
        return tabOpti(str1,str2);
    }
};
