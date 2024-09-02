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
    void morrisPreOrderTraversal(TreeNode* root,vector<int>&preOrder) {
        if(!root) return;
        TreeNode* curr=root;
        while(curr) {
            if(!curr->left) {
                preOrder.push_back(curr->val);
                curr=curr->right;
            }
            else{
                TreeNode* prev=curr->left;
                while(prev->right&&prev->right!=curr) {
                    prev=prev->right;
                }
                if(prev->right==NULL) {
                    prev->right=curr;
                    preOrder.push_back(curr->val);
                    curr=curr->left;
                }
                else{
                    prev->right=NULL;
                    curr=curr->right;
                }
            }
        }
    }

    vector<int> preorderTraversal(TreeNode* root) {
       vector<int> ans;
       morrisPreOrderTraversal(root,ans);
       return ans; 
    }
};