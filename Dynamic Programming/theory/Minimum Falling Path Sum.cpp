class Solution {
public:
    int dp[101][101];
    /*time complexity is O(M*N) and space complexity is O(M*N)*/
    int solve(vector<vector<int>>&matrix,int x,int y,int m,int n) {
        if(x>=m) {
            return 0;
        }
        if(dp[x][y]!=-1) {
            return dp[x][y];
        }
        int ans=INT_MAX;
        int b=solve(matrix,x+1,y,m,n);;
        int l=INT_MAX,r=INT_MAX;
        if(y-1>-1)
        l=solve(matrix,x+1,y-1,m,n);
        if(y+1<n)
        r=solve(matrix,x+1,y+1,m,n);
        ans=min(ans,min(b,min(l,r)));
        return dp[x][y]=ans+matrix[x][y];
    }
    int tab(vector<vector<int>>&matrix) {
        int m=matrix.size();
        int n=matrix[0].size();
        //m==n
        vector<vector<int>>dp(m+1,vector<int>(n+1,0));
        for(int i=0;i<n;i++) {
            dp[m][i]=0;
            dp[m-1][i]=matrix[m-1][i];
        }
        for(int x=m-2;x>-1;x--) {
            for(int y=0;y<n;y++) {
                int ans=INT_MAX;
                int b=dp[x+1][y];
                int l=INT_MAX,r=INT_MAX;
                if(y-1>-1)
                l=dp[x+1][y-1];
                if(y+1<n)
                r=dp[x+1][y+1];
                ans=min(ans,min(b,min(l,r)));
                dp[x][y]=ans+matrix[x][y];
            }
        }
        int ans=INT_MAX;
        for(int i=0;i<n;i++) {
            ans=min(ans,dp[0][i]);
        }
        return ans;
    }
    int tabOpti(vector<vector<int>>&matrix) {
        int m=matrix.size();
        int n=matrix[0].size();
        //m==n
        //vector<vector<int>>dp(m+1,vector<int>(n+1,0));
        vector<int> next(m+1,0);
        vector<int> curr(m+1,0);
        for(int i=0;i<n;i++) {
            // dp[m][i]=0;
            // dp[m-1][i]=matrix[m-1][i];
            next[i]=matrix[m-1][i];
        }
        for(int x=m-2;x>-1;x--) {
            for(int y=0;y<n;y++) {
                int ans=INT_MAX;
                int b=next[y];
                int l=INT_MAX,r=INT_MAX;
                if(y-1>-1)
                l=next[y-1];
                if(y+1<n)
                r=next[y+1];
                ans=min(ans,min(b,min(l,r)));
                curr[y]=ans+matrix[x][y];
            }
            next=curr;
        }
        int ans=INT_MAX;
        for(int i=0;i<n;i++) {
            ans=min(ans,next[i]);
        }
        return ans;
    }

    int minFallingPathSum(vector<vector<int>>& matrix) {
        int m=matrix.size();
        int n=matrix[0].size();
        // int ans=INT_MAX;
        // memset(dp,-1,sizeof(dp));
        // for(int i=0;i<n;i++) {
        //     ans=min(ans,solve(matrix,0,i,m,n));
        // }
        //int ans=tab(matrix);
        int ans=tabOpti(matrix);
        return ans;
    }
};