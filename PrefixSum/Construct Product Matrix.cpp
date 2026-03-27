class Solution {
public:
    const int mod=12345;
    vector<vector<int>> constructProductMatrix(vector<vector<int>>& grid) {
        int n=grid.size();
        int m=grid[0].size();
        vector<vector<int>> res(n,vector<int>(m,0));
        long long prefix=1;
        for(int i=0;i<n;i++) {
            for(int j=0;j<m;j++) {
                res[i][j]=prefix;
                prefix=(prefix*(grid[i][j]))%mod;
            }
        }
        long long suffix=1;
        for(int i=n-1;i>-1;i--) {
            for(int j=m-1;j>-1;j--) {
                res[i][j]=(res[i][j]*suffix)%mod;
                suffix=(suffix*(grid[i][j]))%mod;        
            }
        }
        return res;
    }
};