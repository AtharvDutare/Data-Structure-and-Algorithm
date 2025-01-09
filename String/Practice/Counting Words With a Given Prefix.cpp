//time complexity=O(n) and space complexity=O(1)
//brute force approach
//compare the ech word with the prefix and if the prefix is present in the word then increment the count

class Solution {
public:
    int prefixCount(vector<string>& words, string pref) {
        int n=words.size();
        int m=pref.size();
        int ans=0;
        for(int i=0;i<n;i++) {
            int b=0;
            string t=words[i];
            int k=t.size();
            if(k<m) {
                continue;
            }
            for(int i=0;i<m;i++) {
                if(t[i]!=pref[i]) {
                    b=1;
                    break;
                }
            } 
            if(b==0) {
                ans++;
            }
        }
        return ans;
    }
};