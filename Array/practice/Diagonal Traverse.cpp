class Solution {
public:
    vector<int> findDiagonalOrder(vector<vector<int>>& mat) {
        vector<int> ans;
        int m=mat.size();
        int n=mat[0].size();
        map<int,vector<int>> mp;
        for(int i=0;i<m;i++) {
            for(int j=0;j<n;j++) {
                mp[i+j].push_back(mat[i][j]);
            }
        }
        for(auto &[x,y]:mp) {
            if(x%2==0) {
                reverse(y.begin(),y.end());
            }
            for(auto &t:y) {
                ans.push_back(t);
            }
        }
        return ans;
    }
};