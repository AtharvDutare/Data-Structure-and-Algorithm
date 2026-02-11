class Solution {
public:
    vector<int> findDiagonalOrder(vector<vector<int>>& mat) {
        map<int,vector<int>> mp;
        vector<int> ans;
        for(int i=mat.size()-1;i>=0;i--) {
            for(int j=mat[i].size()-1;j>=0;j--) {
                mp[i+j].push_back(mat[i][j]);
            }
        }

        for(auto &[x,y]:mp) {
            for(auto &t:y) {
                ans.push_back(t);
            }
        }
        return ans;

    }
};