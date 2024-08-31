void dfsFill(int node,vector<bool> &visited,vector<vector<int>> &adj,stack<int>&st){
	    visited[node]=true;
	    for(int &v:adj[node]){
	        if(!visited[v])
	        dfsFill(v,visited,adj,st);
	    }
	    st.push(node);
	    
	}
	void dfsTravsersal(int u,vector<bool>& visited,vector<vector<int>>&adj){
	    visited[u]=true;
	    for(int &v:adj[u]){
	        if(!visited[v]){
	            dfsTravsersal(v,visited,adj);
	        }
	    }
	}
	//Function to find number of strongly connected components in the graph.
    int kosaraju(int V, vector<vector<int>>& adj)
    {
        stack<int> st;
        vector<bool> visited(V,false);
        for(int u=0;u<V;u++){
            if(!visited[u]){
                dfsFill(u,visited,adj,st);
            }
        }
        //reverse the graph/make the reverse graph
        vector<vector<int>> adjRev(V);
        for(int u=0;u<V;u++){
            for(int &v:adj[u]){
                adjRev[v].push_back(u);
            }
        }
        
        int countScc=0;
        visited=vector<bool>(V,false);
        while(!st.empty()){
            int node=st.top();
            st.pop();
            if(!visited[node]){
                dfsTravsersal(node,visited,adjRev);
                countScc++;
            }
        }
        return countScc;
    }