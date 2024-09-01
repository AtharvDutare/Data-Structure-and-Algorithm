class Solution {
public:
    /*time complexity is O(L*N^2) where L is max Length of string*/
    bool isPossible(string &s1,string &s2) {
        if(s1.length()+1!=s2.length()) return false;
        int i=0;
        int j=0;
        while(j<s2.length()) {
            if(s1[i]==s2[j]) {
                i++;
                j++;
            }
            else{
                j++;
            }
        }
        return (i==s1.length()&&j==s2.length());
    }

    int longestStrChain(vector<string>& words) {
        auto lambha=[](string &s1,string &s2) {
            return s1.length()<s2.length();
        };
        sort(words.begin(),words.end(),lambha);
        int n=words.size();
        vector<int>dp(n,1);
        //dp[i] signify the lis which end at i
        int maxi=1;
        for(int i=0;i<n;i++) {
            for(int prev=0;prev<i;prev++) {
                if(isPossible(words[prev],words[i])) {
                    dp[i]=max(1+dp[prev],dp[i]);
                }
            }
        
            maxi=max(maxi,dp[i]);
        }
        return maxi; 
    }
};