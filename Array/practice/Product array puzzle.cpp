//time and space complexity is O(n)
class Solution {
  public:
    vector<int> productExceptSelf(vector<int>& arr) {
        // code here
        int n=arr.size();
        int pro=1;
        vector<int> prefix(n,0);
        for(int i=0;i<n;i++) {
            pro*=arr[i];
            prefix[i]=pro;
        }
        int suf=1;
        vector<int> suffix(n,0);
        for(int i=n-1;i>-1;i--) {
            suf*=arr[i];
            suffix[i]=suf;
        }
        vector<int> ans;
        for(int i=0;i<n;i++) {
            int t=1;
            if(i-1>=0) {
                t*=prefix[i-1];
            }
            if(i+1<n) {
                t*=suffix[i+1];
            }
            ans.push_back(t);
        }
        return ans;
    }
};