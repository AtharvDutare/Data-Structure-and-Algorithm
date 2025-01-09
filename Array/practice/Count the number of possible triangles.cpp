//time comlexity=O(n^2) and space complexity=O(1) with some time complexity optimization
class Solution {
  public:
    // Function to count the number of possible triangles.
    int countTriangles(vector<int>& arr) {
        //3 4 6 7
        int ans=0;
        int n=arr.size();
        sort(arr.begin(),arr.end());
        for(int k=2;k<n;k++) {
            int i=0;
            int j=k-1;
            while(i<j) {
                if(arr[i]+arr[j]>arr[k]) {
                    ans+=(j-i);
                    //find all pair with respect to j
                    j--;
                }
                else {
                    i++;
                }
            }
        }
        return ans;
    }
};