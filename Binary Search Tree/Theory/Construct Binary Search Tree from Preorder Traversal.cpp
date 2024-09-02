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
    TreeNode* preOrderInOrder(vector<int>&preOrder,vector<int>&inOrder,int &preIndex,int inStart,int inEnd,unordered_map<int,int> &mp){
        if(inStart>inEnd) return NULL;
        int element=preOrder[preIndex++];
        TreeNode* root=new TreeNode(element);
        root->left=preOrderInOrder(preOrder,inOrder,preIndex,inStart,mp[element]-1,mp);
        root->right=preOrderInOrder(preOrder,inOrder,preIndex,mp[element]+1,inEnd,mp);
        return root;
    }



    TreeNode* bstFromPreorder(vector<int>& preorder) {
        vector<int> inorder=preorder;
        sort(inorder.begin(),inorder.end());
        unordered_map<int,int> mp;
        for(int i=0;i<inorder.size();i++){
            mp[inorder[i]]=i;
        }
        int index=0;
        TreeNode* ans=preOrderInOrder(preorder,inorder,index,0,preorder.size()-1,mp);
        return ans;
    }
};