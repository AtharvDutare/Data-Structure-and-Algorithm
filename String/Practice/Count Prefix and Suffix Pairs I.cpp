// time complexity: O(n^2) and space complexity: O(1)
// approach: for each pair of words,
// check if the first word is a prefix and suffix of the second word.
class Solution {
public:
    int isPreSuff(string s1,string s2) {
        int n=s1.length();
        int m=s2.length();
        if(n>m) {
            return 0;
        }
        for(int i=0;i<n;i++) {
            if(s1[i]!=s2[i]) {
                return 0;
            }
            if(s1[i]!=s2[m-n+i]) {
                return 0;
            }
        }
        return 1;
        
    } 
    int countPrefixSuffixPairs(vector<string>& words) {
        int n=words.size();
        int ans=0;
        for(int i=0;i<n;i++) {
            for(int j=i+1;j<n;j++) {
                ans+=isPreSuff(words[i],words[j]);
            }
        }
        return ans;
    }
};