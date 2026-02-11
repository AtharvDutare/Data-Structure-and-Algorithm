class Solution {
public:
    vector<vector<int>> generateMatrix(int n) {
        vector<vector<int>> ans(n,vector<int>(n,0));
        int i=0;
        int j=0;
        int maxRow=n-1;
        int maxCol=n-1;
        int value=1;
        while(value<=n*n) {
            for(int k=j;k<=maxCol&&value<=n*n;k++) {
                ans[i][k]=value;
                value++;
            }
            //cout<<value<<endl;
            i++;
            for(int k=i;k<=maxRow&&value<=n*n;k++) {
                ans[k][maxCol]=value;
                value++;
            }
            maxCol--;
            for(int k=maxCol;k>=j&&value<=n*n;k--) {
                ans[maxRow][k]=value;
                value++;
            }
            maxRow--;
            for(int k=maxRow;k>=i&&value<=n*n;k--) {
                ans[k][j]=value;
                value++;
            }
            j++;

        }
        return ans;
    }
};