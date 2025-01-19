#include<bits/stdc++.h>
using namespace std;
// time complexity=O(m*n*log(m*n)) and space complexity=O(m*n)
class Solution {
public:
    typedef pair<int,pair<int,int>> pp;
    int trapRainWater(vector<vector<int>>& heightMap) {
        int m=heightMap.size();
        int n=heightMap[0].size();
        int ans=0;
        vector<pair<int,int>> direction={{1,0},{0,1},{0,-1},{-1,0}};
        vector<vector<int>> visited(m+1,vector<int>(n+1,0));
        priority_queue<pp,vector<pp>,greater<>> pq;
        for(int i=0;i<m;i++) {
            pq.push({heightMap[i][0],{i,0}});
            pq.push({heightMap[i][n-1],{i,n-1}});
            visited[i][0]=visited[i][n-1]=1;
        }
        for(int i=0;i<n;i++) {
            pq.push({heightMap[0][i],{0,i}});
            pq.push({heightMap[m-1][i],{m-1,i}});
            visited[0][i]=visited[m-1][i]=1;
        }
        while(!pq.empty()) {
            pp node=pq.top();
            pq.pop();
            int height=node.first;
            int i=node.second.first;
            int j=node.second.second;
            for(auto &dir:direction) {
                int newX=i+dir.first;
                int newY=j+dir.second;
                if(newX>=0&&newY>=0&&newX<m&&newY<n&&(!visited[newX][newY])) {
                    // this height is the smallest height overall possible 
                    ans+=(max(height-heightMap[newX][newY],0));
                    pq.push({max(height,heightMap[newX][newY]),{newX,newY}});
                    visited[newX][newY]=1;
                }
            }
        }
        return ans;
    }
};