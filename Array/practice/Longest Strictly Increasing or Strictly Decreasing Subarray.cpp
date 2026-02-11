class Solution {
public:
    int longestMonotonicSubarray(vector<int>& nums) {
        int n=nums.size();
        int longInc=1;
        int temp=1;
        for(int i=1;i<n;i++) {
            if(nums[i-1]<nums[i]) {
                temp++;
            }
            else {
                longInc=max(longInc,temp);
                temp=1;
            }
        }
        longInc=max(longInc,temp);
        int longDec=1;
        temp=1;
        for(int i=1;i<n;i++) {
            if(nums[i-1]>nums[i]) {
                temp++;
            }
            else {
                longInc=max(longInc,temp);
                temp=1;
            }
        }
        longDec=max(longDec,temp);
        return max(longInc,longDec);
    }
};