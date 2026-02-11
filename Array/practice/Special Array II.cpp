class Solution {
public:
    vector<bool> isArraySpecial(vector<int>& nums, vector<vector<int>>& queries) {
        int n=nums.size();
        vector<bool> ans(queries.size(),true);
        vector<int> prefix(n,0);
        for(int i=1;i<n;i++) {
            prefix[i]=prefix[i-1];
            if(nums[i-1]%2==nums[i]%2) {
                prefix[i]++;
            }
        }
        for(int i=0;i<queries.size();i++) {
            int x=queries[i][0];
            int y=queries[i][1];
            if(prefix[y]-prefix[x]>0) {
                ans[i]=false;
            }
        }
        return ans;
    }
};