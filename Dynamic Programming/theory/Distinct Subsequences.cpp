class Solution {
public:
    //totally my approach 
    int mod=1e9+7;
    int distSubseq(string &s,string &t,string temp,int i,int j,vector<vector<int>>&dp){
        if(i==s.length()||j==t.length()){
            if(temp==t) return 1;
            else return 0;
        }
        if(dp[i][j]!=-1) return dp[i][j];
        int include=0;
        if(s[i]==t[j])
            include=distSubseq(s,t,temp+s[i],i+1,j+1,dp);
        int exlude=distSubseq(s,t,temp,i+1,j,dp);
        dp[i][j]=(include+exlude);
        return dp[i][j];
    }



    int numDistinct(string s, string t) {
        if(s.length()<t.length()) return 0;
        string temp="";
        vector<vector<int>> dp(s.length(),vector<int>(t.length(),-1));
        int ans=distSubseq(s,t,temp,0,0,dp);
        return ans;
    }
};
//approach 2 using lis 
https://www.youtube.com/watch?v=xElxAuBcvsU