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
    void function(vector<vector<int>> &ans,vector<int> temp,int sum,TreeNode* root){
        if(root==NULL){
            
            return;
        }
        temp.push_back(root->val);
        sum-=root->val;
        function(ans,temp,sum,root->left);
        if(root->left==NULL&&root->right==NULL)
        if(sum==0){
            ans.push_back(temp);
        }
        function(ans,temp,sum,root->right);
    }


    vector<vector<int>> pathSum(TreeNode* root, int targetSum) {
        vector<vector<int>> ans;
        vector<int> temp;
        function(ans,temp,targetSum,root);
        return ans;
    }
};