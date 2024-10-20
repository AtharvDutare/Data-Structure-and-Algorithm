class Solution {
public:
    int findMaxLength(vector<int>& nums) {
        int n=nums.size();
        int ans=0;
        unordered_map<int,int> mp;
        mp[0]=-1;
        int currFreq=0;
        for(int i=0;i<n;i++) {
            if(nums[i]==1) {
                currFreq++;
            }
            else {
                currFreq--;
            }
            if(mp.find(currFreq)!=mp.end()) {
                ans=max(ans,i-mp[currFreq]);
            }
            if(mp.find(currFreq)==mp.end())
            mp[currFreq]=i;
        }
        return ans;
    }
};