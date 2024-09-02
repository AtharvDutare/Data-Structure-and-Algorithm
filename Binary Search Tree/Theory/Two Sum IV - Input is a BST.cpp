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
/*time complexity is O(n*log(N)) and space is O(N)*/
class Solution {
public:
    void inOrderTrav(TreeNode* root,set<int>&ans) {
        if(!root) return ;
        inOrderTrav(root->left,ans);
        ans.insert(root->val);
        inOrderTrav(root->right,ans);
    }
    bool findTarget(TreeNode* root, int k) {
        set<int>inOrder;
        inOrderTrav(root,inOrder);
        //if(inOrder.size()==1) return false;
        for(auto &x:inOrder) {
            int f=k-x;
            if(f!=x&&inOrder.find(f)!=inOrder.end()) {
                return true;
            }
        }
        return false;
        
    }
};
/*time complexity O(N+N)==O(N) and space is O(N)*/
class Solution {
public:
    void inOrderTrav(TreeNode* root,vector<int>&ans) {
        if(!root) return;
        inOrderTrav(root->left,ans);
        ans.push_back(root->val);
        inOrderTrav(root->right,ans);
    }
    bool findTarget(TreeNode* root, int k) {
        vector<int> inOrder;
        inOrderTrav(root,inOrder);
        int i=0;
        int j=inOrder.size()-1;
        while(i<j) {
            if(inOrder[i]+inOrder[j]==k) {
                return true;
            }
            else if(inOrder[i]+inOrder[j]<k){
                i++;
            }
            else{
                j--;
            }
        }
        return false;
    }
};
/*time complexity is O(N) and space is O(H) height of tree*/
class BSTIterator{
    public:
    stack<TreeNode*>st;
    int rev;
    BSTIterator(TreeNode* root,int rev){
        this->rev=rev;
        if(rev==0) {
            while(root) {
                st.push(root);
                root=root->left;
            }
        }
        else{
            while(root) {
                st.push(root);
                root=root->right;
            }
        }
    }
    int next() {
        TreeNode* node=st.top();
        st.pop();
        if(rev==0) {
            if(node->right) {
                TreeNode* prev=node->right;
                while(prev) {
                    st.push(prev);
                    prev=prev->left;
                }
            }
        }
        else{
            if(node->left) {
                TreeNode* prev=node->left;
                while(prev) {
                    st.push(prev);
                    prev=prev->right;
                }
            }
        }
        return node->val;
    }
    bool hasNext() {
        return !st.empty();
    }
};

class Solution {
public:
    bool findTarget(TreeNode* root, int k) {
        BSTIterator small(root,0);
        BSTIterator large(root,1);
        int s=small.next();
        int l=large.next();
        while(s<l) {
            if(s+l==k) {
                return true;
            }
            else if(s+l<k) {
                s=small.next();
            }
            else{
                l=large.next();
            }
        }
        return false;
    }
};