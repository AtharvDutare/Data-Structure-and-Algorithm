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

class Solution {
public:
    int mod=1e9+7;
    int numDistinct(string s, string t) {
        int n=s.length();
        int m=t.length();
        vector<vector<int>>dp(n+1,vector<int>(m+1,0));
        for(int i=0;i<=n;i++) dp[i][0]=1;
        for(int i=1;i<=n;i++) {
            for(int j=1;j<=m;j++) {
                if(s[i-1]==t[j-1]) {
                    dp[i][j]=(dp[i-1][j-1]+dp[i-1][j])%mod;
                }
                else {
                    dp[i][j]=dp[i-1][j];
                }
            }
        }
        return dp[n][m];
    }
};


class FenwickTree {
public:
    FenwickTree(const std::vector<int>& a) : tree(a.size() + 1, 0) {
        for (size_t i = 0; i < a.size(); ++i) {
            inc(i + 1, a[i]);
        }
    }

    void inc(int idx, int delta) {
        while (idx < (int)tree.size()) {
            tree[idx] += delta;
            idx += idx & -idx;
        }
    }

    int prefix_sum(int idx) const {
        int ret = 0;
        while (idx > 0) {
            ret += tree[idx];
            idx -= idx & -idx;
        }
        return ret;
    }

    int range_sum(int l, int r) const {
        return prefix_sum(r) - prefix_sum(l - 1);
    }

private:
    std::vector<int> tree;
};

class Solution {
public:
    int numDistinct(const std::string& s, const std::string& t) {
        int n = (int)s.size();
        std::vector<FenwickTree> suffix;
        suffix.reserve(t.size());
        for (size_t i = 0; i < t.size(); ++i) {
            suffix.emplace_back(std::vector<int>(n, 0));
        }

        for (int i = n - 1; i >= 0; --i) {
            for (int k = (int)t.size() - 1; k >= 0; --k) {
                if (t[k] == s[i]) {
                    if (k + 1 == (int)t.size()) {
                        suffix[k].inc(i + 1, 1);
                    } else if (i + 1 < n) {
                        suffix[k].inc(i + 1, suffix[k + 1].range_sum(i + 2, n));
                    }
                }
            }
        }

        return suffix[0].range_sum(1, n);
    }
};
