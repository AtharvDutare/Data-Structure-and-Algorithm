bool dfs(int n,int currNode,unordered_map<int,vector<int>> &adjList,vector<int>&colors,int currColor){
        colors[currNode]=currColor;
        for(int &v:adjList[currNode]){
            if(colors[currNode]==colors[v]){
                return false;
            }
            if(colors[v]==-1){
                if(dfs(n,v,adjList,colors,!currColor)==false){
                    return false;
                }
            }
        }
        return true;
    }
    bool bfs(int n,int currNode,unordered_map<int,vector<int>>& adjList,vector<int>& colors,int currColor){
        queue<int> q;
        q.push(currNode);
        colors[currNode]=currColor;
        while(!q.empty()){
            int u=q.front();
            q.pop();
            for(int &v:adjList[u]){
                if(colors[u]==colors[v]){
                    return false;
                }
                if(colors[v]==-1){
                    colors[v]=1-colors[u];
                    q.push(v);
                }
            }
        }
        return 1;
    }
    bool isBipartite(vector<vector<int>>& graph) {
        int n=graph.size();
        unordered_map<int,vector<int>> adjList;
        for(int u=0;u<n;u++){
            for(int &v:graph[u]){
                adjList[u].push_back(v);
            }
        }
        vector<int> colors(n,-1);
        for(int u=0;u<n;u++){
            if(colors[u]==-1&&dfs(n,u,adjList,colors,1)==false){
                return false;
            }
        }
        return true;
    }