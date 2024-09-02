class Solution {
  public:
    vector<int> solve(Node* root) {
        //store the value according to level 
        map<int,int> mp;
        queue<pair<Node*,int>>q;
        vector<int> ans;
        //here we are using vertical level 
        q.push({root,0});
        while(!q.empty()) {
            pair<Node*,int> n=q.front();
            q.pop();
            Node* node=n.first;
            int verticalLevel=n.second;
            // if(mp.find(verticalLevel)==mp.end()) {
                
            //     //ans.push_back(node->data);
            // }
            mp[verticalLevel]=node->data;
            if(node->left) {
                q.push({node->left,verticalLevel-1});
            }
            if(node->right) {
                q.push({node->right,verticalLevel+1});
            }
        }
        for(auto &x:mp) {
            ans.push_back(x.second);
        }
        return ans;
        
    }
    vector <int> bottomView(Node *root) {
        vector<int> ans=solve(root);
        return ans;
    }
};