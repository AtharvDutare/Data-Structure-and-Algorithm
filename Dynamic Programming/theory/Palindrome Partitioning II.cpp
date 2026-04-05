class Solution {
public:
    int dp[2001];
    int isPalindrome(string &s,int i,int j) {
        while(i<=j) {
            if(s[i]!=s[j]) {
                return 0;
            }
            i++;
            j--;
        }
        return 1;
    }
    int solve(string &s,int index) {
        if(index>=s.length()) {
            return 0;
        }
        if(dp[index]!=-1) {
            return dp[index];
        }
        int ans=INT_MAX;
        for(int i=index;i<s.length();i++) {
            if(isPalindrome(s,index,i)) {
                ans=min(ans,1+solve(s,i+1));
            }
        }
        return dp[index]=ans;
    }

    int tab(string &s) {
        int n=s.length();
        vector<int> dp(n+1,0);
        for(int index=n-1;index>-1;index--) {
            int ans=INT_MAX;
            for(int i=index;i<n;i++) {
                if(isPalindrome(s,index,i)) {
                    ans=min(ans,1+dp[i+1]);
                }
            }
            dp[index]=ans;
        }
        return dp[0];
    }

    int minCut(string s) {
    //     memset(dp,-1,sizeof(dp));
    //    int ans=solve(s,0);
        int ans=tab(s);
       return --ans; 
    }
};

class Solution {
public:
    int minCut(string s) {
        int n=s.length();
        s=" "+s;
        vector<vector<int>> isPal(n+1,vector<int>(n+1,0));
        for(int g=1;g<=n;g++) {
            for(int i=1,j=g;j<=n;i++,j++) {
                if(g==1) {
                    isPal[i][i]=1;
                }
                else if(g==2) {
                    isPal[i][j]=(s[i]==s[j]);
                }
                else {
                    isPal[i][j] = (s[i] == s[j] && isPal[i + 1][j - 1]);
                }
            }
        } 

        vector<int> dp(n+1,0);
        for(int i=1;i<=n;i++) {
            if(isPal[1][i]) {
                dp[i]=0;
                continue;
            }
            int mini=i-1;
            for(int j=1;j<=i;j++) {
                if(isPal[j][i]) {
                    mini=min(mini,1+dp[j-1]);
                }
                dp[i]=mini;
            }
        }
        return dp[n];
    }
};