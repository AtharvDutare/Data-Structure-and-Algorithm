struct Node
{
    int data;
    struct Node* left;
    struct Node* right;
    
    Node(int x){
        data = x;
        left = right = NULL;
    }
}; */
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
            int horizontalLevel=n.second;
            // if(mp.find(horizontalLevel)==mp.end()) {
                
            //     //ans.push_back(node->data);
            // }
            mp[horizontalLevel]=node->data;
            if(node->left) {
                q.push({node->left,horizontalLevel+1});
            }
            if(node->right) {
                q.push({node->right,horizontalLevel+1});
            }
        }
        for(auto &x:mp) {
            ans.push_back(x.second);
        }
        return ans;
        
    }
    vector<int> levelOrder(Node* root) {
        //vector<vector<int>> ans;
        if(root==NULL) return {};
        vector<int> temp;
        vector<int> ans;
        queue<Node*> q;
        q.push(root);
        q.push(NULL);
        while(!q.empty()){
            Node* local=q.front();
            q.pop();
            if(local==NULL){
                //ans.push_back(temp);
                temp.erase(temp.begin(),temp.end());
                if(!q.empty())
                q.push(NULL);
            }
            else{
                if(temp.size()==0) {
                    ans.push_back(local->data);
                }
                temp.push_back(local->data);
                //cout<<local->val<<" ";
                
                if(local->right){
                    q.push(local->right);
                }
                if(local->left){
                    q.push(local->left);
                }
            }
        }
        return ans;
    }
    
    void rightViewSolve(Node* root,vector<int>&ans,int level) {
        if(!root) return;
        if(level==ans.size()) {
            ans.push_back(root->data);
        }
        
        rightViewSolve(root->right,ans,level+1);
        rightViewSolve(root->left,ans,level+1);
    }

// Should return  right view of tree
class Solution
{
    public:
    //Function to return list containing elements of right view of binary tree.
    vector<int> rightView(Node *root)
    {
       //vector<int> ans=solve(root);
       //vector<int> ans=levelOrder(root);
       vector<int>ans;
       rightViewSolve(root,ans,0);
       return ans;
    }
};