class Solution {
  public:
    int tab2(vector<int> &arr) {
        int n=arr.size();
        vector<int>dp1(n,1),dp2(n,1);
        //dp[i] signify the lis which end at i
        int maxi=0;
        for(int i=0;i<n;i++) {
            for(int prev=0;prev<i;prev++) {
                if(arr[prev]<arr[i]) {
                    dp1[i]=max(1+dp1[prev],dp1[i]);
                }
                
            }
        }
        for(int i=n-1;i>-1;i--) {
            for(int prev=n-1;prev>i;prev--) {
                if(arr[prev]<arr[i]) {
                    dp2[i]=max(1+dp2[prev],dp2[i]);
                }
            }
        }
        for(int i=0;i<n;i++) {
            //below condition
            if(dp1[i]!=1&&dp2[i]!=1)
            maxi=max(maxi,dp1[i]+dp2[i]-1);
        }
        return maxi;
    }
    int LongestBitonicSequence(int n, vector<int> &nums) {
        return tab2(nums);
    }
};