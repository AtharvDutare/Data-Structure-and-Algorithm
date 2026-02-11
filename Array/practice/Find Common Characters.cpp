// Find Common Characters
//Optimal Approach
//Time Complexity: O(n)
//Space Complexity: O(1)
class Solution {
public:
    vector<string> commonChars(vector<string>& words) {
        int n=words.size();
        vector<int> mp(26,0);
        for(int i=0;i<words[0].size();i++) {
            mp[words[0][i]-'a']++;
        }
        for(int i=1;i<n;i++) {
            vector<int> temp(26,0);
            for(int j=0;j<words[i].size();j++) {
                temp[words[i][j]-'a']++;
            }
            for(int j=0;j<26;j++) {
                mp[j]=min(mp[j],temp[j]);
            }
        }
        vector<string> ans;
        for(int i=0;i<26;i++) {
            int t=mp[i];
            while(t--) {
                string t;
                t.push_back(i+'a');
                ans.push_back(t);
            }
        }
        return ans;
    }
};