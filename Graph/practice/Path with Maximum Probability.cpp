class Solution {
public:
/*TIME COMPLEXITY IS O(E*log(V))*/
    double maxProbability(int n, vector<vector<int>>& edges, vector<double>& succProb, int start_node, int end_node) {
        //cout<<setprecision(5);
        unordered_map<int,vector<pair<double,int>>>adjList;
        for(int i=0;i<edges.size();i++) {
            adjList[edges[i][0]].push_back({succProb[i],edges[i][1]});
            adjList[edges[i][1]].push_back({succProb[i],edges[i][0]});
        }
        vector<double> minDist(n,0);
        minDist[start_node]=0;
        priority_queue<pair<double,int>>pq;
        pq.push({1.0,start_node});
        while(!pq.empty()){
            double d=pq.top().first;
            int node=pq.top().second;
            pq.pop();
            for(auto &vec:adjList[node]){
                int adjNode=vec.second;
                double wt=vec.first;
                double dist=wt*d;
                if(dist>minDist[adjNode]){
                    //cout<<d<<" "<<wt<<" "<<minDist[adjNode]<<endl;
                    minDist[adjNode]=dist;
                    pq.push({dist,adjNode});
                }
            }
        }
        return minDist[end_node];
    }
};