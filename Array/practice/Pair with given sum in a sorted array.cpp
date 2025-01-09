//time complexity=O(n) and space complexity=O(n)
class Solution {
  public:
    int countPairs(vector<int> &arr, int target) {
        int n=arr.size();
        int ans=0;
        unordered_map<int,int> mp;
        for(int i=0;i<n;i++) {
            if(mp.find(target-arr[i])!=mp.end()) {
                ans+=mp[target-arr[i]];
            }
            mp[arr[i]]++;
        }
        return ans;
    } 
};