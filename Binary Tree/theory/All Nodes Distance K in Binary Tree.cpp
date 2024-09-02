/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
class Solution {
public:
    void trav(TreeNode* root,TreeNode* prev,unordered_map<TreeNode*,TreeNode*> &parent) {
        if(!root) {
            return ;
        }
        parent[root]=prev;
        trav(root->left,root,parent);
        trav(root->right,root,parent);
    }

    vector<int> bfs(TreeNode* root,unordered_map<TreeNode*,TreeNode*> &parent,int k) {
        int level=0;
        queue<TreeNode*>q;
        unordered_map<TreeNode*,int> visited;
        vector<int>ans;
        visited[root]=1;
        q.push(root);
        while(!q.empty()) {
            int n=q.size();
            
            if(level>k) {
                return ans;
            }
            while(n--) {
                TreeNode* node=q.front();
                if(level==k) {
                    ans.push_back(node->val);
                }
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
        return ans;
    }

    vector<int> distanceK(TreeNode* root, TreeNode* target, int k) {
        unordered_map<TreeNode*,TreeNode*> parent;
        trav(root,NULL,parent);
        vector<int> ans=bfs(target,parent,k);
        return ans;
    }
};