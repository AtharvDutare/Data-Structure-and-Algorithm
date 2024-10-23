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
/*time and space is O(N)*/
class Solution {
public:
    TreeNode* replaceValueInTree(TreeNode* root) {
        queue<pair<TreeNode*,TreeNode*>> q;
        unordered_map<TreeNode*,int> mp;
        mp[NULL]=0;
        int sum=0;
        q.push({NULL,root});
        while(!q.empty()) {
            int nxtSum=0;
            int n=q.size();
            while(n--) {
                pair<TreeNode*,TreeNode*> t=q.front();
                q.pop();
                int no=mp[t.first];
                t.second->val=sum-no;
                int nodeSum=0;
                if(t.second->left) {
                    nodeSum+=t.second->left->val;
                    q.push({t.second,t.second->left});
                }
                if(t.second->right) {
                    nodeSum+=t.second->right->val;
                    q.push({t.second,t.second->right});
                }
                mp[t.second]=nodeSum;
                nxtSum+=nodeSum;
            }
            sum=nxtSum;
        }
        return root;
    }
};