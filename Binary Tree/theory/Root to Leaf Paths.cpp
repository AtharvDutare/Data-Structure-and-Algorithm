/*
Definition for Binary Tree Node
struct Node
{
    int data;
    struct Node* left;
    struct Node* right;

    Node(int x){
        data = x;
        left = right = NULL;
    }
};
*/

class Solution {
  public:
    void preOrder(Node* root,vector<int> temp,vector<vector<int>>&ans) {
        if(!root) {
            return;
        }
        
        temp.push_back(root->data);
        if(!root->left&&!root->right) {
            ans.push_back(temp);
        }
        preOrder(root->left,temp,ans);
        preOrder(root->right,temp,ans);
        temp.pop_back();
    }
  
    vector<vector<int>> Paths(Node* root) {
        vector<vector<int>> ans;
        vector<int>temp;
        preOrder(root,temp,ans);
        return ans;
    }
};