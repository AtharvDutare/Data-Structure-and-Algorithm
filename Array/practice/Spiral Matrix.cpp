class Solution {
public:
    vector<int> spiralOrder(vector<vector<int>>& matrix) {
        int m=matrix.size();
        int n=matrix[0].size();
        int i=0;
        int j=0;
        int maxRow=m-1;
        int maxCol=n-1;
        vector<int> ans;
        while(i<=maxRow&&j<=maxCol) {
            for(int k=j;k<=maxCol;k++) {
                ans.push_back(matrix[i][k]);
            }
            i++;
            for(int k=i;k<=maxRow;k++) {
                ans.push_back(matrix[k][maxCol]);
            }
            maxCol--;
            if(i<=maxRow) {
                for(int k=maxCol;k>=j;k--) {
                    ans.push_back(matrix[maxRow][k]);
                }
                maxRow--;
            }
            if(j<=maxCol) {
                for(int k=maxRow;k>=i;k--) {
                    ans.push_back(matrix[k][j]);
                }
                j++;
            }

        }
        return ans;
    }
};