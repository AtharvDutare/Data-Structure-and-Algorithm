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
    void morrisTraversal(TreeNode* root ,vector<int> &inOrder) {
        if(!root) return;
        TreeNode*curr=root;
        while(curr!=NULL) {
            if(curr->left==NULL) {
                inOrder.push_back(curr->val);
                curr=curr->right;
            }
            else{
                TreeNode* prev=curr->left;
                while(prev->right&&prev->right!=curr) {
                    prev=prev->right;
                }
                if(prev->right==NULL) {
                    prev->right=curr;
                    curr=curr->left;
                }
                else{
                    prev->right=NULL;
                    inOrder.push_back(curr->val);
                    curr=curr->right;
                }
            }
        }
    }
    vector<int> inorderTraversal(TreeNode* root) {
        vector<int> ans;
        morrisTraversal(root,ans);
        return ans;

    }
};