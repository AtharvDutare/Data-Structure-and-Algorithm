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
    TreeNode* deleteNode(TreeNode* root, int key) {
        if(!root) return NULL;
        TreeNode* left=deleteNode(root->left,key);
        TreeNode* right=deleteNode(root->right,key);
        if(root->val==key) {
            if(left&&right) {
                if(left->right) {
                    TreeNode* prev=left->right;
                    while(prev->right) {
                        prev=prev->right;
                    }
                    prev->right=right;
                    root=left;
                }
                else{
                    left->right=right;
                    root=left;
                }
            }
            else if(left) {
                root=left;
            }
            else{
                root=right;
            }
        }
        else{
            root->left=left;
            root->right=right;
        }
        return root;
    }
};