/*
struct Node {
    int data;
    Node *left;
    Node *right;

    Node(int val) {
        data = val;
        left = right = NULL;
    }
};
*/
class Solution
{
    public:
    void inOrder(Node *root,vector<int> &temp){
        if(!root) return;
        inOrder(root->left,temp);
        temp.push_back(root->data);
        inOrder(root->right,temp);
        
    }
    
    vector<int> mergeTwoSortedArray(vector<int> &temp1,vector<int> &temp2){
        vector<int> ans;
        int m=temp1.size();
        int n=temp2.size();
        int i=0;
        int j=0;
        while(i<m&&j<n){
            if(temp1[i]<temp2[j]) {
                ans.push_back(temp1[i]);
                i++;
            }
            else{
                ans.push_back(temp2[j]);
                j++;
            }
        }
        if(i!=m){
            for(int k=i;k<m;k++){
                ans.push_back(temp1[k]);
            }
        }
        if(j!=n){
            for(int k=j;k<n;k++){
                ans.push_back(temp2[k]);
            }
        }
        return ans;
    }
    
    vector<int> merge(Node *root1, Node *root2)
    {   
        vector<int> temp1,temp2;
        inOrder(root1,temp1);
        inOrder(root2,temp2);
        if(!root1) return temp2;
        if(!root2) return temp1;
        vector<int> ans=mergeTwoSortedArray(temp1,temp2);

        return ans;
    }
};