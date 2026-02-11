// Relative Sort Array
// Time Complexity: O(nlogn)
// Space Complexity: O(n)
class Solution {
public:
    vector<int> relativeSortArray(vector<int>& arr1, vector<int>& arr2) {
        map<int,int> mp;
        vector<int> ans;
        for(int i=0;i<arr1.size();i++) {
            mp[arr1[i]]++;
        }
        for(int i=0;i<arr2.size();i++) {
            int t=mp[arr2[i]];
            while(t--) {
                ans.push_back(arr2[i]);
            }
            mp.erase(arr2[i]);
        }
        for(auto &x:mp) {
            int t=x.second;
            while(t--)
            ans.push_back(x.first);
        }
        return ans;
    }
};