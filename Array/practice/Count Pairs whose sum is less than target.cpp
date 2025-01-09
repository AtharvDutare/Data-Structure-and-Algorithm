class Solution {
  public:
    //time complexity=O(nlogn) and space complexity=O(1)
    

    int countPairs(vector<int> &arr, int target) {
        // Your code here
        int n=arr.size();
        sort(arr.begin(),arr.end());
        int i=0;
        int j=n-1;
        int ans=0;
        while(i<j) {
            if(arr[i]+arr[j]<target) {
                ans+=j-i;
                //find all pair with respect to i
                i++;
            }
            else {
                j--;
            }
        }
        return ans;
    }
};