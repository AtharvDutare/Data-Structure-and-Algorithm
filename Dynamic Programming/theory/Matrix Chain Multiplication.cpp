class Solution{
public:
    int dp[101][101];
    /*time complexity is O(N*N*K) and space is O(N*N)*/
    int solve(int arr[],int i,int j) {
        if(i==j) {
            return 0;
        }
        if(dp[i][j]!=-1) {
            return dp[i][j];
        }
        int ans=INT_MAX;
        for(int k=i;k<j;k++) {
            int tempAns=arr[i-1]*arr[k]*arr[j]+solve(arr,i,k)+solve(arr,k+1,j);
            ans=min(tempAns,ans);
        }
        return dp[i][j]=ans;
    }
    /*time complexity is O(N*N*K)*/
    int tab(int arr[],int n) {
        vector<vector<int>>dp(n+1,vector<int>(n+1,0));
        for(int i=1;i<n;i++) {
            dp[i][i]=0;
        }
        
        for(int i=n-1;i>=1;i--) {
            for(int j=i+1;j<n;j++) {
                int ans=INT_MAX;
                for(int k=i;k<j;k++) {
                    int tempAns=arr[i-1]*arr[k]*arr[j]+dp[i][k]+dp[k+1][j];
                    ans=min(tempAns,ans);
                }
                dp[i][j]=ans;
            }
        }
        return dp[1][n-1];
    }

    int matrixMultiplication(int N, int arr[])
    {
        // memset(dp,-1,sizeof(dp));
        // int ans = solve(arr,1,N-1);
        
        int ans=tab(arr,N);
        return ans;
        
    }
};