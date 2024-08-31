#include<iostream>
#include<vector>
#include<list>
#include<unordered_map>
#include<queue>
using namespace std;

template<typename T>
//dont use pair 

class Graph{
    private:
    unordered_map< T,list< T>> adjList;
    vector<vector<T>> adjMatrix;
    public:
    addEdge(T u,T v,int direction){
        // undirected graph->0
        // directed graph->1
        if(direction){
            adjList[u].push_back(v);
        }
        else{
            adjList[u].push_back(v);
            adjList[v].push_back(u);
        }
    }
    addEdgeMatrix(T u,T v,int direction){
        //undirected graph->0
        // directed graph->1
        if(direction)
        adjMatrix[u]=v;
        else{
            adjMatrix[u][v]=1;
            adjMatrix[v][u]=1;
        }
    }

    printAdjList(){
        for(auto x:adjList){
            cout<<"neighour node of "<<x.first<<"-> ";
            for(auto y:x.second){
                cout<<y<<" ";
            }
            cout<<endl;
        }
    }
    printadjMatrix(){
        for(auto x:adjMatrix){
            for(auto y:x){
                cout<<y<<" ";
            }
            cout<<endl;
        }
    }
    //adjList bhi bfs me use karenge
    void bfs(T src,unordered_map<T,bool>&visited){
        queue<T> q;
        q.push(src);
        visited[src]=true;

        while(!q.empty()){
            T fNode=q.front();
            q.pop();
            cout<<" the node is :"<<fNode<<" ";
            for(auto nbr:adjList[fNode]){
                if(!visited[nbr]){
                    cout<<" neighbour"<<nbr<<" ";
                    q.push(nbr);
                    visited[nbr]=true;
                }
            }
            cout<<endl;
        }
    }


    void dfs(T src,unordered_map<T,bool> &visited){
        visited[src]=true;
        cout<<"the node is"<<src<<endl;
        for(auto nbr:adjList[src]){
            if(!visited[nbr]){
                dfs(nbr,visited);
            }
        }
    }

    bool dectectCycleUsingBfs(T src,unordered_map<T,bool>visited){
        queue<T> q;
        unordered_map<T,T>parent;
        q.push(src);
        visited[src]=true;
        parent[src]=-1;
        while(!q.empty()){
            T fNode =q.front();
            q.pop();

            for(auto nbr: adjList[fNode]){
                if(!visited[nbr]){
                    visited[nbr]=true;
                    parent[nbr]=fNode;
                    q.push(nbr);
                }
                if(visited[nbr]&&nbr!=parent[fNode]) return true;
            }
        }
        return false;
    }

    bool detectUndirectedCycleUsingDfs(T src,T parents,unordered_map<T,bool> &visited,unordered_map<T,T> &parent){
        visited[src]=true;
        parent[src]=parents;
        bool sideKaAns=false;
        for(auto nbr:adjList[src]){
            if(!visited[nbr]){
                sideKaAns=detectUndirectedCycleUsingDfs(nbr,src,visited,parent);
            }
            if(sideKaAns){
                return true;
            }
            if(visited[nbr]&&nbr!=parent[nbr])
                return true;
        }
        return false;
    }

    bool detectDirectedCycleUsingDfs(T src,,unordered_map<T,bool> visited,unordered_map<T,bool> DfsVisited){
        visited[src]=true;
        DfsVisited[src]=true;

        for(auto nbr:adjList[src]){
            if(!visited[nbr]){
                bool ans=detectDirectedCycleUsingDfs(nbr,src,visited,parent);
                if(ans) return true;
            }
            if(visited[nbr]&&DfsVisited[nbr]) return true;

        }
        DfsVisited[src]=false;
        return false;
    }

};


int main(){
    Graph<int> g;
    g.addEdge(0,1,1);
    g.addEdge(1,2,1);
    g.addEdge(2,3,1);
    g.addEdge(3,4,1);
    g.addEdge(3,5,1);
    g.addEdge(5,1,1);

    g.printAdjList();
    int n=5;
    unordered_map<int, bool> visited;
    bool ans=false;
    // for(int i=0;i<=n;i++){
    //     if(!visited[i]){
    //         ans=g.detectCycleUsingDfs(i,visited);
    //     }
    // }
    unordered_map<int,int> parent;
    ans=g.detectCycleUsingDfs(0,-1,visited,parent);
    if(ans) cout<<" cycle is present "<<endl;
    else cout<<" cycle is absent "<<endl;

    return 0;
}