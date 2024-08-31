/*
// Definition for a Node.
class Node {
public:
    int val;
    vector<Node*> children;

    Node() {}

    Node(int _val) {
        val = _val;
    }

    Node(int _val, vector<Node*> _children) {
        val = _val;
        children = _children;
    }
};
*/
/*Time complexity is O(n) and space complexity is O(max height of tree==n)*/
class Solution {
public:
    void solve(Node *root ,vector<int>&ans) {
        if(!root) {
            return;
        }
        for(auto child:root->children) {
            solve(child,ans);
        }
        ans.push_back(root->val);
        return;
    }
    vector<int> postorder(Node* root) {
        vector<int> ans;
        solve(root,ans);
        return ans;
    }
};

/*method 2 */
class Solution {
public:
    /*reverse postOrder node ,Right node,left node*/
    void solve(Node* root,vector<int>& ans) {
        stack<Node*> st;
        st.push(root);
        while(!st.empty()) {
            Node* par=st.top();
            st.pop();
            ans.push_back(par->val);
            for(auto &child:par->children) {
                st.push(child);
            }
        }
        reverse(ans.begin(),ans.end());
    }

    vector<int> postorder(Node* root) {
        if(!root) return {};
        vector<int> ans;
        solve(root,ans);
        return ans;
    }
};