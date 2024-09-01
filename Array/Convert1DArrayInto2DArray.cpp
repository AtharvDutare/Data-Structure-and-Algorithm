class Solution {
public:
/*time complexity is O(m*n) and time complexity is O(M*N)*/
    vector<vector<int>> construct2DArray(vector<int>& original, int m, int n) {
        int k=original.size();
        if(k!=m*n) {
            return {};
        }
        int p=0;
        vector<vector<int>> ans(m,vector<int>(n,0));
        for(int i=0;i<m;i++) {
            for(int j=0;j<n;j++) {
                ans[i][j]=original[p++];
            }
        }
        return ans;
    }
};