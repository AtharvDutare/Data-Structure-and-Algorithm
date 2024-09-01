class Solution {
public:
    int m;
    int n;
    int dp[1001][1001];
    /*time complexity is O(m*n) and space complexity is O(m*n) and recursion stack is O(min(n,m)) */
    int solve(string &text1,string &text2,int i,int j) {
        if(i>=m) return 0;
        if(j>=n) return 0;
        if(dp[i][j]!=-1) {
            return dp[i][j];
        }
        int ans=0;
        if(text1[i]==text2[j]) {
            ans=1+solve(text1,text2,i+1,j+1);
        }
        else {
            ans=0+max(solve(text1,text2,i+1,j),solve(text1,text2,i,j+1));
        }
        return dp[i][j]=ans;
    }

    int tab(string text1,string text2) {
        vector<vector<int>>dp(m+1,vector<int>(n+1,0));
        for(int i=m-1;i>-1;i--) {
            for(int j=n-1;j>-1;j--) {
                int ans=0;
                if(text1[i]==text2[j]) {
                    ans=1+dp[i+1][j+1];
                }
                else {
                    ans=0+max(dp[i+1][j],dp[i][j+1]);
                }
                dp[i][j]=ans;
            }
        }
        return dp[0][0];
        int i=0;
        int j=0;
        string printComSeq="";
        while(i<m&&j<n) {
            if(text1[i]==text2[j]) {
                printComSeq.push_back(text1[0]);
            }
            else if(dp[i+1][j]==dp[i][j]) {
                i++;
            }
            else{
                j++;
            }
        }

    }

    int tabOpti(string &text1,string &text2) {
        vector<int>next(n+1,0);
        vector<int> curr(n+1,0);
        for(int i=m-1;i>-1;i--) {
            for(int j=n-1;j>-1;j--) {
                int ans=0;
                if(text1[i]==text2[j]) {
                    ans=1+next[j+1];
                }
                else {
                    ans=0+max(next[j],curr[j+1]);
                }
                curr[j]=ans;
            }
            next=curr;
        }
        return next[0];

    }

    int longestCommonSubsequence(string text1, string text2) {
        m=text1.length();
        n=text2.length();
        // memset(dp,-1,sizeof(dp));
        // int ans=solve(text1,text2,0,0);
        int ans=tabOpti(text1,text2);
        return ans;
    }
};