class Solution {
public:
    /*time complexity is O(N*M) and space complexity is O(N*M)*/
    int minDist(string &word1,string &word2,int i,int j,vector<vector<int>> &dp){
        if(i==word1.length()) return (word2.length()-j);
        if(j==word2.length()) return (word1.length()-i);
        if(dp[i][j]!=-1) return dp[i][j];
        int ans=0;
        if(word1[i]==word2[j])
            ans=minDist(word1,word2,i+1,j+1,dp);
        else{
            int inserted=1+minDist(word1,word2,i+1,j,dp);
            int deleted=1+minDist(word1,word2,i,j+1,dp);
            int replaced=1+minDist(word1,word2,i+1,j+1,dp);
            ans=min(inserted,min(deleted,replaced));
        }
        dp[i][j]=ans;
        return dp[i][j];
    }

    int tab(string &s1,string &s2) {
        int m=s1.length();
        int n=s2.length();
        vector<vector<int>>dp (m+1,vector<int>(n+1,0));
        for(int i=0;i<=m;i++) {
            dp[i][n]=m-i;
        }
        for(int i=0;i<=n;i++) {
            dp[m][i]=n-i;
        }

        for(int i=m-1;i>-1;i--) {
            for(int j=n-1;j>-1;j--) {
                int ans=0;
                if(s1[i]==s2[j])
                    ans=dp[i+1][j+1];
                else{
                    int inserted=1+dp[i+1][j];
                    int deleted=1+dp[i][j+1];
                    int replaced=1+dp[i+1][j+1];
                    ans=min(inserted,min(deleted,replaced));
                }
                dp[i][j]=ans;
            }
        }
        return dp[0][0];
    }
    /*tabulation optimization not work 1065 / 1146 testcases passed*/
    int tabOpti(string &s1,string &s2) {
        int m=s1.length();
        int n=s2.length();
        //vector<vector<int>>dp (m+1,vector<int>(n+1,0));
        vector<int>curr(n+1,0);
        vector<int>next(n+1,0);
        // for(int i=0;i<=m;i++) {
        //     dp[i][n]=m-i;
        // }
        curr[n]=m;
        for(int i=0;i<=n;i++) {
            next[i]=n-i;
        }

        for(int i=m-1;i>-1;i--) {
            curr[n]=i;
            for(int j=n-1;j>-1;j--) {
                int ans=0;
                if(s1[i]==s2[j])
                    ans=next[j+1];
                else{
                    int inserted=1+next[j];
                    int deleted=1+curr[j+1];
                    int replaced=1+next[j+1];
                    ans=min(inserted,min(deleted,replaced));
                }
                curr[j]=ans;
            }
            next=curr;
        }
        return next[0];
    }

    int minDistance(string word1, string word2) {
        if(word1.length()==0) return word2.length();
        if(word2.length()==0) return word1.length();
        // vector<vector<int>>dp(word1.length(),vector<int>(word2.length(),-1));
        // int ans=minDist(word1,word2,0,0,dp);
        int ans=tabOpti(word1,word2);
        return ans;
    }
};