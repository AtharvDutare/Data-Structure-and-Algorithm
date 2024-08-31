	//topological sort done in DAG(directed acyclic graph)
    vector<int> topoSortBfs(int V, vector<int> adj[]) 
	{
        //KAHN'S ALGO
	    vector<int> indegree(V,0);
	    for(int u=0;u<V;u++){
	       for(auto &v:adj[u]){
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
	    return ans;
	}