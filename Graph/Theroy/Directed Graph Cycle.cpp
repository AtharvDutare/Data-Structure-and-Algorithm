    // if cycle is present then it is not possible to make indegree of that vertices indegree=0
    // indegree size decrease 
    bool topoBfs(int V,vector<int> adj[]){
        vector<int> indegree(V,0);
        for(int u=0;u<V;u++){
            for(int &v:adj[u]){
                indegree[v]++;
            }
        }
        queue<int> q;
        for(int u=0;u<V;u++){
            if(indegree[u]==0){
                q.push(u);
            }
        }
        vector<int> ans;
        while(!q.empty()){
            int u=q.front();
            ans.push_back(u);
            q.pop();
            for(int &v:adj[u]){
                indegree[v]--;
                if(indegree[v]==0){
                    q.push(v);
                }
            }
            
        }
        return ans.size()!=V;
    }
    bool isCyclic(int V, vector<int> adj[]) {
        return topoBfs(V,adj);
    }