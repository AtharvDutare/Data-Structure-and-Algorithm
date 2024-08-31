class Solution {
public:
    int m;
    int n; 
    int solve(vector<vector<int>>&grid,int x,int y,vector<vector<int>>&visited,vector<vector<int>>&dp) {
        if(x==m-1&&y==n-1) {
            return grid[m-1][n-1];
        }
        if(dp[x][y]!=-1) {
            return dp[x][y];
        }
        if(x==0&&y==1) {
            cout<<"atharv"<<endl;
        }
        int ans=40001;
        int dx[]={1,0,-1,0};
        int dy[]={0,-1,0,1};
        for(int i=0;i<4;i++) {
            int newX=x+dx[i];
            int newY=y+dy[i];
            
            if(newX>-1&&newY>-1&&newX<m&&newY<n&&!visited[newX][newY]) {
                //cout<<newX<<" "<<newY<<endl;
                visited[newX][newY]=1;
                int tempAns=solve(grid,newX,newY,visited,dp)+grid[x][y];
                if(x==0&&y==1) {
                cout<<newX<<" "<<newY<<" "<<tempAns<<" "<<endl;
                }
                ans=min(ans,tempAns);
                visited[newX][newY]=0;
                
            }
            // else if(x==0&&y==1) {
            //     cout<<newX<<" "<<newY<<" ";
            //     if(newX>-1&&newY>-1&&newX<m&&newY<n) {
            //         cout<<"visited";
            //     }
            //     cout<<endl;
            // }
        }
        return dp[x][y]=ans;

    }
    int minPathSum(vector<vector<int>>& grid) {
        m=grid.size();
        n=grid[0].size();
        cout<<m<<" "<<n<<endl;
        vector<vector<int>>dp(m+1,vector<int>(n+1,-1));
        dp[m-1][n-1]=grid[m-1][n-1];
        vector<vector<int>> visited(m+1,vector<int>(n+1,0));
        visited[0][0]=1;
        int ans=solve(grid,0,0,visited,dp);
        // for(auto x:dp) {
        //     for(auto y:x) {
        //         cout<<y<<" ";
        //     }
        //     cout<<endl;
        // }
        return ans;
    }
};