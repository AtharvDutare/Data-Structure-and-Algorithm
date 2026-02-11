//Optimized Solution
// Time Complexity: O(n)
// Space Complexity: O(1)
class Solution {
public:
    bool isArraySpecial(vector<int>& nums) {
        int n=nums.size();
        if(n==1) {
            return true;
        }
        int f=nums[0]%2==0?1:0;
        for(int i=1;i<n;i++) {
            f=!f;
            if(f) {
                if(nums[i]%2!=0) {
                    return false;
                }
            }
            else {
                if(nums[i]%2==0) {
                    return false;
                }
            }
        }
        return true;
    }
};