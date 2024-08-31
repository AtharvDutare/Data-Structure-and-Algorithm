#include<bits/stdc++.h>
using namespace std;
typedef pair<int,int> p;

	//Function to find sum of weights of edges of the Minimum Spanning Tree.
    int spanningTree(int V, vector<vector<int>> adj[])
    {
        int ans=0;
        priority_queue<p,vector<p>,greater<p>> pq;
        pq.push({0,0});
        
        vector<bool> inMst(V);
        while(!pq.empty()){
            int node=pq.top().second;
            int nodeW=pq.top().first;
            pq.pop();
            if(inMst[node]){
                continue;
            }
            inMst[node]=true;
            ans+=nodeW;
            for(auto &vec:adj[node]){
                int adjNode=vec[0];
                int adjNodeW=vec[1];
                if(inMst[adjNode]==false){
                pq.push({adjNodeW,adjNode});
                }
            }
        }
        return ans;
    }