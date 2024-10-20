class Solution{
  public:
    //Function to count subarrays with 1s and 0s.
    long long int countSubarrWithEqualZeroAndOne(int arr[], int n)
    {
        long long ans=0;
        unordered_map<int,int>mp;
        int currFreq=0;
        mp[currFreq]=1;
        for(int i=0;i<n;i++) {
            if(arr[i]) {
                currFreq++;
            }
            else{
                currFreq--;
            }
            if(mp.find(currFreq)!=mp.end()) {
                ans+=mp[currFreq];
            }
            mp[currFreq]++;
        }
        return ans;
    }
};