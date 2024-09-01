/*approach is to find longest palindromic sequence and insert character which is not in sequence
example leetcode
    sequence is eee
    remaining ltcod
    add remaining ltcod
*/
class Solution {
public:
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
    int init(string &s) {
        int n=s.length();
        memset(dp,-1,sizeof(dp));
        int t=solve(s,0,n-1);
        return n-t;
    }
    int minInsertions(string s) {
        return init(s);
    }
};