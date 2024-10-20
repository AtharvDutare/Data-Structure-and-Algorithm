class GfG
{
    int maxLen(int arr[], int n)
    {
        int ans=0;
        HashMap<Integer,Integer> mpp=new HashMap<>();
        int currSum=0;
        mpp.put(0,-1);
        for(int i=0;i<n;i++) {
            currSum+=arr[i];
            if(mpp.containsKey(currSum)) {
                ans=Math.max(ans,i-mpp.get(currSum));
            }
            if(!mpp.containsKey(currSum)) {
                mpp.put(currSum,i);
            }
        }
        return ans;
    }
}
//c++
// class Solution {
//   public:
//     int maxLen(vector<int>& arr, int n) {
//         int ans=0;
//         unordered_map<int,int> mp;
//         int currSum=0;
//         mp[currSum]=-1;
//         for(int i=0;i<n;i++) {
//             currSum+=arr[i];
//             int temp=currSum;
//             if(mp.find(temp)!=mp.end()) {
//                 ans=max(ans,i-mp[temp]);
//             }
//             if(mp.find(currSum)==mp.end()) {
//                 mp[currSum]=i;
//             }
//         }
//         return ans;
//     }
// };