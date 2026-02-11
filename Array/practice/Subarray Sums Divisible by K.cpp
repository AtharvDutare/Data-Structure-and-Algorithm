class Solution {
public:
    int subarraysDivByK(vector<int>& arr, int k) {
        int n=arr.size();
        unordered_map<int,int>mp;
        int ans=0;
        int prefixSum=0;
        mp[0]=1;
        for(int i=0;i<n;i++){
            prefixSum+=arr[i];
            int rem=prefixSum%k;
            rem=(rem+k)%k;
            ans+=mp[rem];
            mp[rem]++;
        }
        return ans;
    }
};