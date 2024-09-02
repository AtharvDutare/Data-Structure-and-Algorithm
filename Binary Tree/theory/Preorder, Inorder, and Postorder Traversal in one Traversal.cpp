void preInPostTraversal(TreeNode* root) {
    stack<pair<TreeNode*,int>> st;
    vector<int> pre,in,post;
    st.push({root,1});
    while(!st.empty()) {
        pair<TreeNode*,int> node=q.front();
        q.pop();
        if(node.second==1) {
            node.second++;
            pre.push(node.first);
            st.push(node);
            if(node->left) {
                st.push({node->left,1});
            }
        }
        else if(node.second==2) {
            node.second++;
            in.push(node.first);
            st.push(node);
            if(node->right) {
                st.push({node->right,1});
            }
        }
        else{
            post.push(node.first);
        }
    }
}