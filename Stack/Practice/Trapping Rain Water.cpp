// my approach is to find the maximum element to the left and right of the current element
// and then take the minimum of the two and subtract the current element from it and add it to the answer
// this is done for all the elements in the array
// the time complexity of this approach is O(n) and the space complexity is O(n)
class Solution {
  public:
    //Function finds the prevoius greatest element which is greater than the current element
    vector<int> prevGreatest(vector<int>& arr) {
        int val=arr[0];
        int n=arr.size();
        vector<int> ans(n,-1);
        for(int i=1;i<n;i++) {
            val=max(val,arr[i]);
            ans[i]=val;
        }
        return ans;
    }
    //Function finds the next greatest element which is greater than the current element
    vector<int> nextGreatest(vector<int> &arr) {
        int n=arr.size();
        int val=arr[n-1];
        vector<int> ans(n,-1);
        for(int i=n-2;i>=0;i--) {
            val=max(val,arr[i]);
            ans[i]=val;
        }
        return ans;
    }
  
    int maxWater(vector<int> &arr) {
        // code here
        vector<int> left=prevGreatest(arr);
        vector<int> right=nextGreatest(arr);
        int ans=0;
        int n=arr.size();
        for(int i=0;i<n;i++) {
            int l=left[i];
            int r=right[i];
            if(l!=-1&&r!=-1) {
                ans+=(min(l,r)-arr[i]);
                //cout<<min(l,r)<<endl;
            }
        }
        return ans;
    }
};