vector<int> diagonal(Node* root) {
    vector<int> ans;
    if(root==NULL) return ans;
    queue<Node*> q;
    q.push(root);
    while(!q.empty()) {
        Node* front=q.front();
        q.pop();
        while(front!=NULL) {
            ans.push_back(front->val);
            if(front->left!=NULL) q.push(front->left);
            front=front->right;
        }
        //at each while loop level increase
    }
    return ans;
}