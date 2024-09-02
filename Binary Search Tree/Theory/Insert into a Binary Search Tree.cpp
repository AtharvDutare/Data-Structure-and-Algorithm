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
// my approach not work
    void trav(TreeNode* root,int val) {
        if(!root) return;
        if(root->left) {
            if(root->left->val<val&&root->val>val) {
                TreeNode* t=new TreeNode(val);
                t->left=root->left;
                root->left=t;
                return;
            }
            if(root->left->val>val) {
                trav(root->left,val);
            }
        }
        else if(root->right) {
            if(root->right->val>val&&root->val<val) {
                TreeNode* t=new TreeNode(val);
                t->right=root->right;
                root->right=t;
                return;
            }
            if(root->right->val<val) {
                trav(root->right,val);
            }
        }
        else{
            TreeNode* t=new TreeNode(val);
            if(root->val>val) {
                root->left=t;
            }
            else{
                root->right=t;
            }
        }
        return;
    }
    TreeNode* insertIntoBST(TreeNode* root, int val) {
        if(!root) return new TreeNode(val);
        TreeNode* curr=root;
        while(true) {
            if(curr->val<val) {
                if(curr->right) curr=curr->right;
                else{
                    TreeNode* t=new TreeNode(val);
                    curr->right=t;
                    break;
                }
            }
            else{
                if(curr->left) curr=curr->left;
                else{
                    TreeNode* t=new TreeNode(val);
                    curr->left=t;
                    break;
                }
            }
        }
        return root;
    }
};