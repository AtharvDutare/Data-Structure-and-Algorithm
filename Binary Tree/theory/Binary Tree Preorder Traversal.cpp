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
    void preOrder(TreeNode* root,vector<int> &temp){
        if(root==NULL) return;
        temp.push_back(root->val);
        preOrder(root->left,temp);
        preOrder(root->right,temp);
    }
    void preOrderStack(TreeNode* root,vector<int>& temp) {
        if(!root) return;
        stack<TreeNode*> backStack;
        backStack.push(root);
        while(!backStack.empty()) {
            TreeNode* node=backStack.top();
            temp.push_back(node->val);
            backStack.pop();
            if(node->right!=NULL) {
                backStack.push(node->right);
            }
            if(node->left!=NULL) {
                backStack.push(node->left);
            }
        }
    }
    vector<int> preorderTraversal(TreeNode* root) {
        vector<int> ans;
        preOrder(root,ans);
        return ans;
    }
};