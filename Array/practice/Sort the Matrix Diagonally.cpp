class Solution {
public:
    vector<vector<int>> diagonalSort(vector<vector<int>>& mat) {
        int m=mat.size();
        int n=mat[0].size();
        unordered_map<int,vector<int>> mp;
        for(int i=0;i<m;i++) {
            for(int j=0;j<n;j++) {
                mp[i-j].push_back(mat[i][j]);
            }
        }
        for(auto &[x,y]:mp) {
            sort(y.begin(),y.end());
        }

        for(int i=m-1;i>=0;i--) {
            for(int j=n-1;j>=0;j--) {
                mat[i][j]=mp[i-j].back();
                mp[i-j].pop_back();
            }
        }

        return mat;
    }
};

class Solution {
public:
    vector<vector<int>> diagonalSort(vector<vector<int>>& mat) {
        int m=mat.size();
        int n=mat[0].size();
        unordered_map<int,vector<int>> mp;
        for(int i=0;i<m;i++) {
            for(int j=0;j<n;j++) {
                mp[i-j].push_back(mat[i][j]);
            }
        }
        for(auto &[x,y]:mp) {
            sort(y.begin(),y.end());
        }
        for(int i=0;i<m;i++) {
            int j=0;
            int t=i-j;
            vector<int> sortedArr=mp[t];
            int w=0;
            for(int p=i,q=j;p<m&&q<n&&w<sortedArr.size();p++,q++,w++) {
                mat[p][q]=sortedArr[w];
            }
        }
        for(int j=0;j<n;j++) {
            int i=0;
            int t=i-j;
            vector<int> sortedArr=mp[t];
            int w=0;
            for(int p=i,q=j;p<m&&q<n&&w<sortedArr.size();p++,q++,w++) {
                mat[p][q]=sortedArr[w];
            }
        }
        return mat;
    }
};