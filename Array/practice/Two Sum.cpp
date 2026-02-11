//Brute Force Approach 
//Time Complexity: O(n^2)
//Space Complexity: O(1)
class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {
        int n=nums.size();
        for(int i=0;i<n;i++) {
            for(int j=i+1;j<n;j++) {
                if(nums[i]+nums[j]==target) {
                    return {i,j};
                }
            }
        }
        return {-1,-1};
    }
};
//Optimal Approach
//Time Complexity: O(n)
//Space Complexity: O(n)
class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {
        int n=nums.size();
        unordered_map<int,int> mp;
        for(int i=0;i<n;i++) {
            if(mp.find(target-nums[i])!=mp.end()) {
                return {mp[target-nums[i]],i};
            }
            else {
                mp[nums[i]]=i;
            }
        }
        return {-1,-1};
    }
};