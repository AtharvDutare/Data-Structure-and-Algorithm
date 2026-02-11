class Solution {
public:
    vector<vector<int>> spiralMatrixIII(int rows, int cols, int rStart, int cStart) {
        vector<vector<int>> ans;
        int move=1;
        while(ans.size()<rows*cols){
            for(int i=0;i<move;i++){
                if((0<=rStart&&rStart<rows)&&(0<=cStart&&cStart<cols))
                ans.push_back(vector<int>{rStart,cStart});
                cStart++;
            }
            for(int i=0;i<move;i++){
               if((0<=rStart&&rStart<rows)&&(0<=cStart&&cStart<cols))
                ans.push_back(vector<int>{rStart,cStart});
                rStart++;
            }
            move++;
            for(int i=0;i<move;i++){
                if((0<=rStart&&rStart<rows)&&(0<=cStart&&cStart<cols))
                ans.push_back(vector<int>{rStart,cStart});
                cStart--;
            }
            for(int i=0;i<move;i++){
                if((0<=rStart&&rStart<rows)&&(0<=cStart&&cStart<cols))
                ans.push_back(vector<int>{rStart,cStart});
                rStart--;
            }
            move++;
        }
        return ans;
    }
};