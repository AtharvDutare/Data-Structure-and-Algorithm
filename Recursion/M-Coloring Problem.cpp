class Solution{
public:
    bool isSafe(int node,int m,int n,bool graph[101][101],vector<int> color,int col) {
        for(int i=0;i<n;i++) {
            if(i!=node&&graph[i][node]==1&&col==color[i]) {
                return false;
            }
        }
        return true;
    }

    bool solve(int node,int m,int n,bool graph[101][101],vector<int> color) {
        if(node==n) {
            return true;
        }
        for(int i=1;i<=m;i++) {
            if(isSafe(node,m,n,graph,color,i)) {
                color[node]=i;
                if(solve(node+1,m,n,graph,color)==true) return true;
                color[node]=0;
            }
        }
        return false;
    }


    // Function to determine if graph can be coloured with at most M colours such
    // that no two adjacent vertices of graph are coloured with same colour.
    bool graphColoring(bool graph[101][101], int m, int n) {
        vector<int> color(n,0);
        if(solve(0,m,n,graph,color)==true) return true;
        return false;
    }
};