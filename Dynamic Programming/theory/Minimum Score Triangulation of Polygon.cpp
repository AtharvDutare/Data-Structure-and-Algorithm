class Solution {
public:
    int minScoreTriangulation(vector<int>& arr) {
        int n=arr.size();
        vector<vector<int>> dp(n,vector<int>(n,0));
        for(int g=0;g<n;g++) {
            for(int i=0,j=g;j<n;i++,j++) {
                if(g==0||g==1) {
                    dp[i][j]=0;
                }
                else if(g==2) {
                    dp[i][j]=arr[i]*arr[i+1]*arr[j];
                }
                else {
                    int mini=1e9;
                    for(int k=i+1;k<j;k++) {
                        mini=min(mini,dp[i][k]+arr[i]*arr[k]*arr[j]+dp[k][j]);
                    }
                    dp[i][j]=mini;
                }
            }
        }
        return dp[0][n-1];
    }
};