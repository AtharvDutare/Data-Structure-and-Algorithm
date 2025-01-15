//greedy approach not work because of negative numbers
//time complexity=O(n) and space complexity=O(1)
//valid for positive numbers only
class Solution {
  public:
    int longestSubarray(vector<int>& arr, int k) {
        // code here
        int n=arr.size();
        int j=0;
        int sum=0;
        while(j<n&&sum+arr[j]<=k) {
            sum+=arr[j];
            j++;
        }
        int ans=0;
        if(j<n) {
            ans=max(ans,j+1);
        }
        int i=0;
        while(j<n) {
            sum-=arr[i++];
            while(j<n&&sum+arr[j]<=k) {
                sum+=arr[j];
                j++;
            }
            ans=max(ans,j-i+1);
        }
        return ans;
    }
};
//optimized approach
//time complexity=O(n) and space complexity=O(n)
//hashMap is used to store the prefix sum and its index with least index value 
//first we check that if prefix sum is equal to k if yes then ans=max(ans,i+1) this prefix sum from start
// then we check if prefix sum-k is present in map if yes then ans=max(ans,i-mp[rem])
// i-mp[rem] is correct not i-mp[rem]+1 because mp[rem] give index prev of index of starting of subarray sum k
// then finally we store the prefix sum and its index in map with least index value
class Solution {
  public:
    int longestSubarray(vector<int>& arr, int k) {
        // code here
        int n=arr.size();
        int ans=0;
        unordered_map<int,int> mp;
        int cumSum=0;
        for(int i=0;i<n;i++) {
            cumSum+=arr[i];
            if(cumSum==k) {
                ans=max(ans,i+1);
            }
            int rem=cumSum-k;
            if(mp.find(rem)!=mp.end()) {
                ans=max(ans,i-mp[rem]);
            }
            if(mp.find(cumSum)==mp.end()) {
                mp[cumSum]=i;
            }
        }
        return ans;
    }
};