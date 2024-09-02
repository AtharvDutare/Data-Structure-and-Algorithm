/*
struct Node {
    int data;
    Node *left;
    Node *right;

    Node(int val) {
        data = val;
        left = right = NULL;
    }
};
*/
class Solution {
  public:
    void trav(Node* root,Node* prev,unordered_map<Node*,Node*> &parent,int node,Node* &start) {
        if(!root) {
            return ;
        }
        if(root->data==node) start=root;
        parent[root]=prev;
        trav(root->left,root,parent,node,start);
        trav(root->right,root,parent,node,start);
    }

    int bfs(Node* root,unordered_map<Node*,Node*> &parent) {
        int level=0;
        queue<Node*>q;
        unordered_map<Node*,int> visited;
        visited[root]=1;
        q.push(root);
        while(!q.empty()) {
            int n=q.size();
            while(n--) {
                Node* node=q.front();
                q.pop();
                if(parent[node]&&!visited[parent[node]]) {
                    visited[parent[node]]=1;
                    q.push(parent[node]);
                }
                if(node->left&&!visited[node->left]) {
                    visited[node->left]=1;
                    q.push(node->left);
                }
                if(node->right&&!visited[node->right]) {
                    visited[node->right]=1;
                    q.push(node->right);
                }

            }
            level++;
            
        }
        return level;
    }
    int minTime(Node* root, int target) 
    {
        unordered_map<Node*,Node*> parent;
        Node* start=NULL;
        trav(root,NULL,parent,target,start);
        int ans=bfs(start,parent);
        return --ans;
    }
};