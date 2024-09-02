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
    void solve(TreeNode* root,vector<int> &arr) {
        if(!root)
        return;
        solve(root->left,arr);
        solve(root->right,arr);
        arr.push_back(root->val);
    }
    // void solveStack(TreeNode* root,vector<int>& arr) {
    //     if(!root) return;
    //     stack<TreeNode*> st;
    //     st.push(root);
    //     while(!st.empty()) {
    //         TreeNode* curr=st.top();
    //         st.pop();
    //         if(curr!=NULL)
    //         arr.push_back(curr->val);
    //         while(curr->right) {
    //             st.push(curr->right);
    //             curr=curr->right;
    //         }
    //         while(curr->left) {
    //             st.push(curr->left);
    //             curr=curr->left;
    //         }
    //         cout<<curr->val<<endl;
            
    //     }
    //     reverse(arr.begin(),arr.end());
    // }

    vector<int> postOrder2Stack(TreeNode* root) {
        vector<int> postOrder;
        if(!root) return postOrder;
        stack<TreeNode*> st1,st2;
        st1.push(root);
        while(!st1.empty()) {
            TreeNode* node=q.front();
            q.pop();
            st2.push(node);
            if(node->left) {
                st1.push(node->left);
            }
            if(node->right) {
                st1.push(node->right);
            }
        }
        while(!st2.empty()) {
            int t=q.top()->val;
            postOrder.push_back(t);
            q.pop();
        }
        return postOrder;
    }


    vector<int> postorderTraversal(TreeNode* root) {
        vector<int> ans;
        //solve(root,ans);
        solveStack(root,ans);
        return ans;
    }
};