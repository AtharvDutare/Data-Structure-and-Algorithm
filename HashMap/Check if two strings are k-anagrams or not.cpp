class Solution {
  public:
    bool areKAnagrams(string str1, string str2, int k) {
        int n=str1.length();
        int m=str2.length();
        if(n!=m) {
            return 0;
        }
        unordered_map<char,int> mp;
        for(int i=0;i<n;i++) {
            mp[str1[i]]++;
        }
        int c=0;
        for(int i=0;i<n;i++) {
            mp[str2[i]]--;
            if(mp.find(str2[i])==mp.end()||mp[str2[i]]<0) {
                c++;
            }
            if(c>k) {
                return 0;
            }
        }
        return 1;
    }
};