//approach is to store the prefix sum in a map and check if the difference of the current prefix sum
// and the target is present in the map or not.
// If it is present then we have found the subarray with the given sum.
// If the difference is 0 then the subarray starts from the 0th index and ends at the current index.
// If the difference is not 0 then the subarray starts from the index after the index where the difference is present and ends at the current index.
//time complexity=O(n) and space complexity=O(n)
class Solution {
  public:
    vector<int> subarraySum(vector<int> &arr, int target) {
        int n=arr.size();
        unordered_map<int,int> mp;
        mp[0]=-1;
        int cumSum=0;
        for(int i=0;i<n;i++) {
            cumSum+=arr[i];
            int t=cumSum-target;
            if(mp.find(t)!=mp.end()) {
                if(t==0) {
                    return {1,i+1};
                }
                else {
                    return {mp[t]+2,i+1};
                }
            }
            mp[cumSum]=i;
        }
        return {-1};
    }https://www.geeksforgeeks.org/problems/subarray-with-given-sum-1587115621/1
};