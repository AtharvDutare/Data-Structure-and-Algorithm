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
    int maxDepth(TreeNode* root){
        if(root==NULL) return 0;
        int leftSide=maxDepth(root->left);
        int rightSide=maxDepth(root->right);
        int ans=1+max(leftSide,rightSide);
        return ans;
    }
    bool isBalanced(TreeNode* root) {
        if(root==NULL) return true;
        int leftHeight=maxDepth(root->left);
        int rightHeight=maxDepth(root->right);
        int ans=abs(leftHeight-rightHeight);
        bool leftSide=isBalanced(root->left);
        bool rightSide=isBalanced(root->right);
        if(leftSide&&rightSide&&(ans<=1)) return true;
        else return false;
    }
};