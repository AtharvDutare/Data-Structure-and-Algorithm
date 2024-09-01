class Solution {
public:
    int tabOpti(string &text1,string &text2) {
        int m=text1.length();
        int n=text2.length();
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
    int init(string &s1,string &s2) {
        int ans=tabOpti(s1,s2);
        return s1.length()+s2.length()-2*ans;

    }
    int minDistance(string word1, string word2) {
        int ans=init(word1,word2);
        return ans;
    }
};