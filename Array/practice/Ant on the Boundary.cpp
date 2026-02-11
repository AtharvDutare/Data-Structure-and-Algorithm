class Solution {
public:
    int returnToBoundaryCount(vector<int>& nums) {
        int n=nums.size();
        int b=0;
        int ans=0;
        for(int i=0;i<n;i++) {
            int d=b+nums[i];
            if(d==0) {
                ans++;
            }
            // else if(d>0&&b<0 || d<0&&b>0) {
            //     ans++;
            // }
            b=d;
        }
        return ans;
    }
};