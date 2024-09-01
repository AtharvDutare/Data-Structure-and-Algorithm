class Solution {
public:

    int lis(vector<int>&nums,int prev,int curr,vector<vector<int>>&dp){
        if(curr>=nums.size()){
            return 0;
        }
        if(dp[prev+1][curr]!=-1) return dp[prev+1][curr];
        int include=0;
        if(prev==-1||nums[prev]<nums[curr]){
            include=1+lis(nums,curr,curr+1,dp);
        }
        int exclude=lis(nums,prev,curr+1,dp);
        dp[prev+1][curr]=max(include,exclude);
        return dp[prev+1][curr];
    }
    
    int tab(vector<int>&arr) {
        int n=arr.size();
        vector<vector<int>>dp(n+2,vector<int>(n+1,0));
        for(int curr=n-1;curr>-1;curr--) {
            for(int prev=curr-1;prev>=-1;prev--) {
                int include=0;
                if(prev==-1||arr[prev]<arr[curr]){
                    /*remember if index shifting of dp then all dp state shift*/
                    include=1+dp[curr+1][curr+1];
                }
                /*remember if index shifting of dp then all dp state shift*/
                int exclude=dp[prev+1][curr+1];
                dp[prev+1][curr]=max(include,exclude);
            }
        }
        return dp[0][-1+1];
    }
    /*not initiution so its ok*/
    int tab2(vector<int> &arr) {
        int n=arr.size();
        vector<int>dp(n,1);
        //dp[i] signify the lis which end at i
        int maxi=1;
        for(int i=0;i<n;i++) {
            for(int prev=0;prev<i;prev++) {
                if(arr[prev]<arr[i]) {
                    dp[i]=max(1+dp[prev],dp[i]);
                }
            }
        
            maxi=max(maxi,dp[i]);
        }
        return maxi;
    }

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
                if(arr[prev]<arr[i]&&1+dp[prev]>dp[i]) {
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
    /*time complexity is O(n*log(n)) and space is O(N) we can override the input arr but which not pefer in interview*/
    int tabBinarySearch(vector<int> &arr) {
        int n=arr.size();
        vector<int>temp;
        temp.push_back(arr[0]);
        for(int i=1;i<n;i++) {
            if(arr[i]>temp.back()) {
                temp.push_back(arr[i]);
            }
            else{
                int index=lower_bound(temp.begin(),temp.end(),arr[i])-temp.begin();
                temp[index]=arr[i];
            }
        }
        return temp.size();
    }

    int lengthOfLIS(vector<int>& nums) {
        // int prev=-1;
        // int curr=0;
        // int n=nums.size();
        // vector<vector<int>>dp(n+1,vector<int>(n+1,-1));
        // int ans=lis(nums,prev,curr,dp);

        //int ans=tab(nums);
        // int ans=tab2(nums);

        //int ans=tabBinarySearch(nums);
        return ans;
    }
};