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
// optimized solution
//time complexity: O(n+m) where n is the number of words in words1 and m is the number of words in words2
//space complexity: O(n)

// approach: create a frequency array for each word in words1
// then create a max frequency array for all words in words2.
// Then for each word in words1, check if it is a subset of the max frequency array.
// If it is not a subset of the max frequency array, then add it to the answer.
// This is because if a word is a subset of the max frequency array, then it is a subset of all words in words2.

class Solution {
public:
    vector<string> wordSubsets(vector<string>& words1, vector<string>& words2) {
        int n=words1.size();
        int m=words2.size();
        vector<vector<int>> freq;
        for(int i=0;i<n;i++) {
            string s=words1[i];
            vector<int> t(26,0);
            for(int j=0;j<s.length();j++) {
                t[s[j]-'a']++;
            }
            freq.push_back(t);
        }
        vector<int> freq1(26,0);
        for(int i=0;i<m;i++) {
            string s=words2[i];
            vector<int> t(26,0);
            for(int j=0;j<s.length();j++) {
                t[s[j]-'a']++;
            }
            for(int k=0;k<26;k++) {
                freq1[k]=max(freq1[k],t[k]);
            }
        }
        vector<string> ans;
        for(int i=0;i<n;i++) {
            vector<int> t1=freq[i];
            int b1=0;
            for(int j=0;j<26;j++) {
                if(t1[j]<freq1[j]) {
                    b1=1;
                    break;
                }
            }
            if(!b1) {
                ans.push_back(words1[i]);
            }
        }
        return ans;
    }
};