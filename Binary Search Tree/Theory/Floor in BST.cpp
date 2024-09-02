class Solution{

public:
    int floor(Node* root, int x) {
        if(!root) return -1;
        int ans=-1;
        while(root) {
            if(root->data==x) {
                return x;
            }
            else if(root->data<x) {
                ans=root->data;
                root=root->right;
            }
            else{
                root=root->left;
            }
        }
        return ans;
    }
};