/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 * };
 */
class Solution {
public:
    vector<vector<int>> levelOrder(TreeNode* root) {
        vector<vector<int>> ans;
        if(root==NULL) return ans;
        vector<int> temp;
        queue<TreeNode*> q;
        q.push(root);
        q.push(NULL);
        while(!q.empty()){
            TreeNode* local=q.front();
            q.pop();
            if(local==NULL){
                ans.push_back(temp);
                temp.erase(temp.begin(),temp.end());
                if(!q.empty())
                q.push(NULL);
            }
            else{
                temp.push_back(local->val);
                cout<<local->val<<" ";
                if(local->left){
                    q.push(local->left);
                }
                if(local->right){
                    q.push(local->right);
                }
            }
        }
        return ans;
    }
};