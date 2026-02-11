class Solution {
public:
    vector<int> productExceptSelf(vector<int>& nums) {
        int n=nums.size();
        vector<int> ans(n,1);
        int leftProduct=1;
        int rightProduct=1;
        for(int i=0;i<n;i++){
            ans[i]*=leftProduct;
            leftProduct=nums[i]*leftProduct;
        }
        for(int i=n-1;i>=0;i--){
            ans[i]*=rightProduct;
            rightProduct=nums[i]*rightProduct;
        }
        return ans;
    }
};