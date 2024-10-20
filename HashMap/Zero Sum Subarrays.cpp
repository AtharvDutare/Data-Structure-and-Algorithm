class Solution{
    //Function to count subarrays with sum equal to 0.
    public static long findSubarray(long[] arr ,int n) 
    {
        long ans=0L;
        HashMap<Long,Long> mp=new HashMap<>();
        long currSum=0L;
        mp.put(currSum,1L);
        for(int i=0;i<n;i++) {
            currSum+=arr[i];
            if(mp.containsKey(currSum)) {
                ans=ans+mp.get(currSum);
            }
            mp.put(currSum,mp.getOrDefault(currSum,0L)+1);
        }
        return (long)ans;
    }
}
//c++
// class Solution{
// public:
//     typedef long long int val;
//     //Function to count subarrays with sum equal to 0.
//     long long int findSubarray(vector<long long int> &arr, int n ) {
//         val ans=0;
//         unordered_map<val,val> mp;
//         int currSum=0;
//         mp[0]=1;
//         for(int i=0;i<n;i++) {
//             currSum+=arr[i];
//             if(mp.find(currSum)!=mp.end()) {
//                 ans+=mp[currSum];
//             }
//             mp[currSum]++;
//         }
//         return ans;
        
//     }
// };