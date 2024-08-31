    vector<int> bellman_ford(int V, vector<vector<int>>& edges, int S) {
        vector<int> minDist(V,1e8);
        minDist[S]=0;
        for(int i=0;i<=V-1;i++){
            for(auto &e:edges){
                int u=e[0];
                int v=e[1];
                int w=e[2];
                if(minDist[u]!=1e8&&(minDist[u]+w<minDist[v])){
                    minDist[v]=minDist[u]+w;
                    if(i==V-1) return {-1};
                }
            }
        }
        return minDist;
        
    }