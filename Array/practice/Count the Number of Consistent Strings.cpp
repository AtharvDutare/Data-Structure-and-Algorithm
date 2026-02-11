class Solution {
public:
    int countConsistentStrings(string allowed, vector<string>& words) {
        int ans=0;
        unordered_map<char,int> mp;
        vector<unordered_map<char,int>> vmp;
        for(auto &x:allowed) {
            mp[x]++;
        }
        for(auto &x:words) {
            unordered_map<char,int> temp;
            for(char &ch:x) {
                temp[ch]++;
            }
            vmp.push_back(temp);
        }
        for(auto &x:vmp) {
            unordered_map<char,int> temp=x;
            for(auto &t:temp) {
                if(mp.find(t.first)==mp.end()) {
                    ans++;
                    break;
                }
            }
        } 
        return words.size()-ans;
    }
};