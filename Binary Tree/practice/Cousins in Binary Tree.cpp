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
/*time complexity is O(N) and space is O(1)*/
class Solution {
public:
    bool isCousins(TreeNode* root, int x, int y) {
        pair<TreeNode*,int> xNode;
        pair<TreeNode*,int> yNode;
        queue<TreeNode*>q;
        q.push(root);
        int level=0;
        while(!q.empty()) {
            int k=q.size();
            while(k--) {
                TreeNode* t=q.front();
                q.pop();
                if(t->left) {
                    if(t->left->val==x) {
                        //cout<<"for X "<<t<<" "<<level+1<<endl;
                        xNode={t,level+1};
                    }
                    if(t->left->val==y) {
                        //cout<<"for Y "<<t<<" "<<level+1<<endl;
                        yNode={t,level+1};
                    }
                    q.push(t->left);
                }
                if(t->right) {
                    if(t->right->val==x) {
                        //cout<<"for X "<<t<<" "<<level+1<<endl;
                        xNode={t,level+1};
                    }
                    if(t->right->val==y) {
                        //cout<<"for Y "<<t<<" "<<level+1<<endl;
                        yNode={t,level+1};
                    }
                    q.push(t->right);
                }
            }
            level++;
        }
        // if(xNode.second==yNode.second) {
        //     return xNode.first!=yNode.first;
        // }
        // return false;
        return (xNode.second==yNode.second)&&(xNode.first!=yNode.first);
        
    }
    

};