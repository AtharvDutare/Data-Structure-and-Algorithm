    typedef pair<int,int> p;
    vector<int> parent;
    vector<int> rank;
    
    int find (int x) {
        if (x == parent[x]) 
            return x;
    
        return parent[x] = find(parent[x]);
    }
    
    void Union (int x, int y) {
        int x_parent = find(x);
        int y_parent = find(y);
    
        if (x_parent == y_parent) 
            return;
    
        if(rank[x_parent] > rank[y_parent]) {
            parent[y_parent] = x_parent;
        } else if(rank[x_parent] < rank[y_parent]) {
            parent[x_parent] = y_parent;
        } else {
            parent[x_parent] = y_parent;
            rank[y_parent]++;
        }
    }
	public:
	//Function to find sum of weights of edges of the Minimum Spanning Tree.
    int spanningTree(int V, vector<vector<int>> adj[])
    {
        
        parent.resize(V,0);
        iota(parent.begin(),parent.end(),0);
        rank.resize(V,1);
        int ans=0;
        
        priority_queue<vector<int>,vector<vector<int>>,greater<vector<int>>> pq;
        for(int u=0;u<V;u++){
            for(auto &vec:adj[u]){
                int v=vec[0];
                int w=vec[1];
                pq.push({w,u,v});
            }
        }
        int count=V-1;
        while(!pq.empty()&&count){
            vector<int> node=pq.top();
            pq.pop();
            int w=node[0];
            int u=node[1];
            int v=node[2];
            if(find(u)!=find(v)){
                ans+=w;
                Union(u,v);
                count--;
            }
        }
        return ans;
        
        
    }
