class Solution {
public:

    bool isSafe(int n,int row,int col,vector<string> &board) {
        //row check
        for(int i=row;i>=0;i--) {
            if(board[i][col]=='Q') {
                return false;
            }
        }
        //diagonal left
        for(int i=row,j=col;i>=0&&j>=0;i--,j--) {
            if(board[i][j]=='Q') {
                return false;
            }
        }
        //diagonal right
        for(int i=row,j=col;i>=0&&j<n;i--,j++) {
            if(board[i][j]=='Q') {
                return false;
            }
        } 
        return true;      
    }

    void solve(int n,int row,vector<string> board,vector<vector<string>>& ans) {
        if(row==n) {
            ans.push_back(board);
            return;
        }
        for(int col=0;col<n;col++) {
            if(isSafe(n,row,col,board)) {
                board[row][col]='Q';
                solve(n,row+1,board,ans);
                board[row][col]='.';
            }
        }
    }

    vector<vector<string>> solveNQueens(int n) {
        vector<string> board(n,string(n,'.'));
        vector<vector<string>> ans;
        solve(n,0,board,ans);
        return ans;

    }
};