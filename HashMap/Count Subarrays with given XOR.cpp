class Solution {
  public:
    long subarrayXor(vector<int> &arr, int k) {
        int n=arr.size();
        long ans=0;
        unordered_map<int,int> mp;
        int x_or=0;
        mp[0]=1;
        for(int i=0;i<n;i++) {
            x_or^=arr[i];
            int t=x_or^k;
            ans+=mp[t];
            mp[x_or]++;
        }
        return ans;
    }
};