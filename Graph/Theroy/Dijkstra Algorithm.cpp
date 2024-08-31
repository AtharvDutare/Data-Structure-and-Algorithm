vector <int> dijkstra(int V, vector<vector<int>> adj[], int S)
    {
        priority_queue<pair<int,int>,vector<pair<int,int>>,greater<pair<int,int>>> pq;
        pq.push({0,S});
        vector<int> result(V,INT_MAX);
        result[S]=0;
        while(!pq.empty()){
            int d=pq.top().first;
            int node=pq.top().second;
            pq.pop();
            for(auto &vec:adj[node]){
                int adjNode=vec[0];
                int wt=vec[1];
                if(d+wt<result[adjNode]){
                    result[adjNode]=d+wt;
                    pq.push({d+wt,adjNode});
                }
            }
        }
        return result;
    }