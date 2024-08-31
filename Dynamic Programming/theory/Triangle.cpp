class Solution {
public:
    int dp[201][201];
        /*time complexity is O(M*M) and space complexity is O(M*M) and recursion stack is O(M)*/
    int solve(vector<vector<int>>& tri,int x,int y,int m){
        if(x>=m) {
            return 0;
        }
        if(dp[x][y]!=-1) {
            return dp[x][y];
        }
        int ans=INT_MAX;
        ans=min(ans,min(solve(tri,x+1,y,m),solve(tri,x+1,y+1,m))+tri[x][y]);
        return dp[x][y]=ans;
    }
    /*time complexity is O(M*M) and space complexity is O(M*M)*/
    int tab(vector<vector<int>>& tri) {
        int m=tri.size();
        vector<vector<int>>dp(m+1,vector<int>(m+1,0));
        for(int i=0;i<=m;i++) {
            dp[m][i]=0;
        }
        for(int x=m-1;x>-1;x--) {
            for(int y=x;y>-1;y--) {
                int ans=INT_MAX;
                ans=min(ans,min(dp[x+1][y],dp[x+1][y+1])+tri[x][y]);
                dp[x][y]=ans;
            }
        }
        return dp[0][0];
    }
    /*time complexity is O(m*m) and space is O(m)*/
    int tabOpti(vector<vector<int>>&tri) {
        int m=tri.size();
        vector<int>next(m+1,0);
        vector<int>curr(m+1,0);
        for(int x=m-1;x>-1;x--) {
            for(int y=x;y>-1;y--) {
                int ans=INT_MAX;
                ans=min(ans,min(next[y],next[y+1])+tri[x][y]);
                curr[y]=ans;
            }
            next=curr;
        }        
        return curr[0];

    }

    int minimumTotal(vector<vector<int>>& triangle) {
        // int m=triangle.size();
        // memset(dp,-1,sizeof(dp));
        // int ans=solve(triangle,0,0,m);
        int ans=tabOpti(triangle);
        return ans;
    }
};