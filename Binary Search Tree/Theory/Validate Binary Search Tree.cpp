//approach not work 
class Solution {
public:
    bool isValidBST(TreeNode* root) {
        if(!root) return 1;
        bool left=isValidBST(root->left);
        bool right=isValidBST(root->right);
        if(left==0||right==0) return false;
        int leftVal=root->left?root->left->val:INT_MIN;
        int rightVal=root->right?root->right->val:INT_MAX;
        if(leftVal<root->val&&root->val<rightVal){
            return true;
        }
        return false;
    }
};
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
    bool checkBST(TreeNode* root,long long lb,long long ub){
        if(root==NULL) return true;
        if(root->val>lb&&root->val<ub){
            bool leftSide=checkBST(root->left,lb,root->val);
            bool rightSide=checkBST(root->right,root->val,ub);
            return leftSide&&rightSide;
        }
        else{
            return false;
        }
    }
    bool isValidBST(TreeNode* root) {
        long long lb=LLONG_MIN;
        long long ub=LLONG_MAX;
        bool ans=checkBST(root,lb,ub);
        return ans;
    }
};