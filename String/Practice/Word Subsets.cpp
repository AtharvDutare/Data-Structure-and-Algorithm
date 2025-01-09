// my solution TLE on 45/56 test cases
// Time complexity: O(n*m) where n is the number of words in words1 and m is the maximum length of a word in words1
// Space complexity: O(n*m)
// approach: create a frequency array for each word in words1 and words2.
// Then for each word in words1,
// check if it is a subset of any word in words2. 
//If it is not a subset of any word in words2, then add it to the answer.
class Solution {
public:
    vector<string> wordSubsets(vector<string>& words1, vector<string>& words2) {
        vector<vector<int>> freq1,freq2;
        for(int i=0;i<words1.size();i++) {
            vector<int> t(26,0);
            int m=words1[i].length();
            for(int j=0;j<m;j++) {
                t[words1[i][j]-'a']++;
            }
            freq1.push_back(t);
        }
        for(int i=0;i<words2.size();i++) {
            vector<int> t(26,0);
            int m=words2[i].length();
            for(int j=0;j<m;j++) {
                t[words2[i][j]-'a']++;
            }
            freq2.push_back(t);
        }
        vector<string> ans;
        for(int i=0;i<words1.size();i++) {
            int b=0;
            for(int j=0;j<words2.size();j++) {
                vector<int> t1=freq1[i];
                vector<int> t2=freq2[j];
                for(int k=0;k<26;k++) {
                    if(t1[k]<t2[k]) {
                        b=1;
                        break;
                    }
                }
                if(b) {
                    break;
                }
            }
            if(!b) {
                ans.push_back(words1[i]);
            }
        }
        return ans;
    }
};