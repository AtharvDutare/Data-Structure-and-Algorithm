// approach: calculate the sum of the array 
// and then iterate through the array 
//and check if the left sum is equal to the right sum
// if yes then return the index
// else return -1

//time complexity: O(n) and space complexity: O(1)
class Solution {
  public:
    // Function to find equilibrium point in the array.
    int findEquilibrium(vector<int> &arr) {
        // code here
        int n=arr.size();
        int sum=0;
        for(int i=0;i<n;i++) {
            sum+=arr[i];
        }
        int left=0;
        for(int i=0;i<n;i++) {
            left+=arr[i];
            if(left-arr[i]==sum-left) {
                return i;
            }
        }
        return -1;
    }
};