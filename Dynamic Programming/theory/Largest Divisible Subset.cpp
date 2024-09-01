class Solution {
public:
    /*time complexity is O(n^2) and space is O(N)*/
    vector<int> tabPrint(vector<int> &arr) {
        int n=arr.size();
        vector<int>dp(n,1),hash(n,0);
        int lastIndex=0;
        //accumulate(hash.begin(),hash.end(),0);
        //dp[i] signify the lis which end at i
        int maxi=1;
        for(int i=0;i<n;i++) {
            hash[i]=i;
            for(int prev=0;prev<i;prev++) {
                if(arr[i]%arr[prev]==0&&1+dp[prev]>dp[i]) {
                    dp[i]=dp[prev]+1;
                    hash[i]=prev;

                }
            }
            if(dp[i]>maxi) {
                maxi=dp[i];
                lastIndex=i;
            }
        }

        vector<int> track;
        track.push_back(arr[lastIndex]);
        while(hash[lastIndex]!=lastIndex) {
            lastIndex=hash[lastIndex];
            track.push_back(arr[lastIndex]);
        }
        reverse(track.begin(),track.end());
        return track;
    }

    vector<int> largestDivisibleSubset(vector<int>& nums) {
        vector<int> temp;
        vector<int> ans;
        sort(nums.begin(),nums.end());
        ans=tabPrint(nums);
        return ans;

    }
};