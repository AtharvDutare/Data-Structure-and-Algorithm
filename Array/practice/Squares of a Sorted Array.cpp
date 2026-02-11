// Bruteforce Solution
// Time Complexity=O(nlogn)
// Space Complexity=O(n)
class Solution {
public:
    vector<int> sortedSquares(vector<int>& nums) {
        map<int,int> mp;
        for(int i=0;i<nums.size();i++) {
            mp[abs(nums[i])]++;
        }
        vector<int> ans;
        for(auto &x:mp) {
            int t=x.second;
            while(t--) {
                ans.push_back(x.first*x.first);
            }
        }
        return ans;
    }
};
// Optimized Solution
// Time Complexity=O(n)
// Space Complexity=O(1)
class Solution {
public:
    vector<int> sortedSquares(vector<int>& nums) {
        int n=nums.size();
        int left=0;
        int right=n-1;
        int pos=n-1;
        vector<int> ans(n,0);
        while(left<=right) {
            if(abs(nums[left])<abs(nums[right])) {
                ans[pos--]=nums[right]*nums[right];
                right--;
            }
            else {
                ans[pos--]=(nums[left]*nums[left]);
                left++;
            }
        }
        return ans;
    }
};