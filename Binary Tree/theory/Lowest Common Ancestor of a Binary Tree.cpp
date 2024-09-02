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
    TreeNode* lowestCommonAncestor(TreeNode* root, TreeNode* p, TreeNode* q) {
        if(root==NULL) return NULL;
        if(root->val==p->val) return p;
        if(root->val==q->val) return q;

        TreeNode* leftSide=lowestCommonAncestor(root->left,p,q);
        TreeNode* rightSide=lowestCommonAncestor(root->right,p,q);
        if(leftSide!=NULL&&rightSide!=NULL) return root;
        if(leftSide==NULL) return rightSide;
        else return leftSide;
    } 
};