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
    void inOrdered(TreeNode *root,vector<int> &temp){
        if(root==NULL){
            return;
        }
        inOrdered(root->left,temp);
        temp.push_back(root->val);
        inOrdered(root->right,temp);
    }
    void inOrderStack(TreeNode* root,vector<int>&ans) {
        stack<TreeNode*> st;
        //st.push(root);
        TreeNode* curr=root;
        while(curr!=NULL||!st.empty()) {
            while(curr!=NULL) {
                st.push(curr);
                curr=curr->left;
            }
            curr=st.top();
            st.pop();
            ans.push_back(curr->val);
            curr=curr->right;
        }
    }
    vector<int> inorderTraversal(TreeNode* root) {
        vector<int> ans;
        //inOrdered(root,ans);
        inOrderStack(root,ans);
        return ans;

    }
};