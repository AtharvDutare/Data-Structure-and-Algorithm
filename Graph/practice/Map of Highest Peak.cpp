//my approach -> multi level bfs try to maximize the level of water cells and minimize the level of land cells
// time complexity O(m*n)
// space complexity O(m*n)
class Solution {
public:
    vector<vector<int>> highestPeak(vector<vector<int>>& isWater) {
        int m=isWater.size();
        int n=isWater[0].size();
        vector<vector<int>> visited(m,vector<int>(n,0));
        vector<pair<int,int>> direction={{1,0},{0,-1},{-1,0},{0,1}};
        queue<pair<int,int>> q;
        for(int i=0;i<m;i++) {
            for(int j=0;j<n;j++) {
                if(isWater[i][j]) {
                    q.push({i,j});
                    isWater[i][j]=0;
                    visited[i][j]=1;
                }
                else {
                    isWater[i][j]=INT_MAX;
                }
            }
        }
        int level=1;
        while(!q.empty()) {
            int k=q.size();
            while(k--) {
                pair<int,int> node=q.front();
                q.pop();
                int x=node.first;
                int y=node.second;
                // cout<<x<<" "<<y<<endl;
                for(auto &dir:direction) {
                    int dx=dir.first;
                    int dy=dir.second;
                    int newX=x+dx;
                    int newY=y+dy;
                    if(newX>=0&&newY>=0&&newX<m&&newY<n&&!visited[newX][newY]) {
                        isWater[newX][newY]=min(isWater[newX][newY],level);
                        visited[newX][newY]=1;
                        q.push({newX,newY});
                    }
                }
            }
            level++;
        }
        return isWater;


    }
};