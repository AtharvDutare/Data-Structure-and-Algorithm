class Solution {
public:
    int numSquares(int n) {
        vector<int> dp(n+1,0);
        for(int i=1;i<=n;i++) {
            dp[i]=i;
        }
        dp[1]=1;
        for(int i=1;i<=n;i++) {
            for(int j=1;j<=sqrt(i);j++) {
                dp[i]=min(dp[i],i/(j*j)+dp[i%(j*j)]);
            }
        }
        for(int i=1;i<=n;i++) {
            cout<<dp[i]<<" ";
        }cout<<endl;
        return dp[n];
    }
};