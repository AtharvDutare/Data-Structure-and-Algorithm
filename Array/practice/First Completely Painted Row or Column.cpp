// My first Approach
// Test case failed at 618/1058
// Time complexity: O(n*m)
// Space complexity: O(n*m)
class Solution {
public:
    int firstCompleteIndex(vector<int>& arr, vector<vector<int>>& mat) {
        int m=mat.size();
        int n=mat[0].size();
        vector<vector<pair<int,int>>> newMat(m,vector<pair<int,int>>(n,{0,0}));
        unordered_map<int,pair<int,int>> mp;
        for(int i=0;i<m;i++) {
            for(int j=0;j<n;j++) {
                mp[mat[i][j]]={i,j};
            }
        }
        for(int i=0;i<arr.size();i++) {
            pair<int,int> t=mp[arr[i]];
            int x=t.first;
            int y=t.second;
            //column
            int c1=0;
            if(x-1>-1) {
                c1+=newMat[x-1][y].second;
            }
            if(x+1<m) {
                c1+=newMat[x+1][y].second;
            }
            if(c1+1==m) {
                return i;
            }
            int r1=0;
            if(y-1>-1) {
                r1+=newMat[x][y-1].first;
            }
            if(y+1<n) {
                r1+=newMat[x][y+1].second;
            }
            if(r1+1==n) {
                return i;
            }
            newMat[x][y]={r1+1,c1+1};
        }
        return arr.size();
    }
};
// my second apporach
// Time complexity: O(n*m)
// Space complexity: O(n+m)

class Solution {
public:
    int firstCompleteIndex(vector<int>& arr, vector<vector<int>>& mat) {
        int m=mat.size();
        int n=mat[0].size();
        vector<int>row(m,0);
        vector<int>col(n,0);
        unordered_map<int,pair<int,int>> mp;
        for(int i=0;i<m;i++) {
            for(int j=0;j<n;j++) {
                mp[mat[i][j]]={i,j};
            }
        }
        for(int i=0;i<arr.size();i++) {
            pair<int,int> t=mp[arr[i]];
            int x=t.first;
            int y=t.second;
            row[x]++;
            col[y]++;
            if(row[x]==n||col[y]==m) {
                return i;
            }
        }
        return arr.size();
    }
};