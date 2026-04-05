
class Solution {
  public:
    int cutRod(vector<int> &arr) {
        int n=arr.size();
        // code here
        vector<int>dp(n+1,0);
        for(int i=1;i<=n;i++) {
            for(int j=1;j<=i;j++) {
                dp[i]=max(arr[j-1]+dp[i-j],dp[i]);
            }
        }
        return dp[n];
    }
};