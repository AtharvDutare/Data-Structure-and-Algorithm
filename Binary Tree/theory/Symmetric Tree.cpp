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
    bool twoTread(TreeNode* left,TreeNode* right){
        if(!right&&!left) return 1;
        if(!right||!left) return 0;
        
        bool leftSide=twoTread(left->left,right->right);
        bool rightSide=twoTread(left->right,right->left);
        bool value=(left->val==right->val);
        return (leftSide&&rightSide&&value);
    }

    bool isSymmetric(TreeNode* root) {
        return twoTread(root->left,root->right);
    }
};