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
    vector<vector<int>> zigzagLevelOrder(TreeNode* root) {
       vector<vector<int>> ans;
       vector<int> tmp;
       if(root==NULL) return ans;
       queue<pair<TreeNode*,int>> q;
        q.push({root,0});
        q.push({NULL,0});
        while(!q.empty()){
            pair<TreeNode*,int>tepo=q.front();
            TreeNode* temp=tepo.first;
            int hd=tepo.second;
            q.pop();
            if(temp==NULL){
                if(hd&1==1){
                reverse(tmp.begin(),tmp.end());
                ans.push_back(tmp);
                }
                else {
                    ans.push_back(tmp);
                }
                tmp.resize(0);
                if(!q.empty())
                q.push({NULL,hd+1});
            }
            else{
                tmp.push_back(temp->val);
                
                    if(temp->left){
                        q.push({temp->left,hd+1});
                    }
                    if(temp->right){
                        q.push({temp->right,hd+1});
                    }
                }
            }
        return ans;
    }
};