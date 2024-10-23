class Solution {
public:
    int leastBricks(vector<vector<int>>& wall) {
        int n=wall.size();
        unordered_map<int,int>mp;
        for(int i=0;i<n;i++) {
            int su=0;
            for(int j=0;j<wall[i].size()-1;j++) {
                su+=wall[i][j];
                mp[su]++;
            }
        }
        int f=0;
        for(auto &x:mp) {
            if(x.second>f) {
                f=x.second;
            }
        }

        return n-f;
    }
};