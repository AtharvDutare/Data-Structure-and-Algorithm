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
    void solve(TreeNode* root,TreeNode* &prev) {
        if(!root) return;
        solve(root->right,prev);
        solve(root->left,prev);
        root->right=prev;
        root->left=NULL;
        prev=root;
    }

    void stackAppraoch(TreeNode* root) {
        stack<TreeNode*>st;
        st.push(root);
        while(!st.empty()) {
            TreeNode* node=st.top();
            st.pop();
            if(node->right) {
                st.push(node->right);
            }
            if(node->left) {
                st.push(node->left);
            }
            if(!st.empty())
            node->right=st.top();
            node->left=NULL;
        }
    }

    void morris(TreeNode* root) {
        if(!root) return;
        TreeNode* curr=root;
        while(curr) {
            if(curr->left==NULL) {
                curr=curr->right;
            }
            else{
                TreeNode* prev=curr->left;
                while(prev->right) {
                    prev=prev->right;
                }
                prev->right=curr->right;
                curr->right=curr->left;
                curr->left=NULL;
                curr=curr->right;
            }
        }
    }
    void flatten(TreeNode* root) {
       if(!root) return;
       //TreeNode* prev=NULL;
       //solve(root,prev);
       //morris(root);
       stackAppraoch(root);
        
    }
};