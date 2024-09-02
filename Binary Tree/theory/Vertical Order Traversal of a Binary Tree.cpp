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
    vector<vector<int>> verticalTraversal(TreeNode* root) {
        map<int,map<int,vector<int>>> mp;
        queue<pair<TreeNode*,pair<int,int>>>q;
        q.push({root,{0,0}});
        while(!q.empty()){
            auto p=q.front();
            q.pop();
            TreeNode* temp=p.first;
            int x=p.second.first;
            int y=p.second.second;
            mp[x][y].push_back(temp->val);
            if(temp->left)
                q.push({temp->left,{x-1,y+1}});
            if(temp->right)
                q.push({temp->right,{x+1,y+1}});
        }
        vector<vector<int>> ans;
        for(auto t:mp){
            vector<int> temp;
            for(auto k:t.second){
                if(k.second.size()>1) sort(k.second.begin(),k.second.end());
                for(int i=0;i<k.second.size();i++) temp.push_back(k.second[i]);
            }
            ans.push_back(temp);
        }
        return ans;
        }
};