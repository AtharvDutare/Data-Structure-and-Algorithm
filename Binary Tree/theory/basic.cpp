 #include<iostream>
#include<queue>
#include<limits.h>
using namespace std;

class TreeNode{

    public:
    int val;
    TreeNode* left;
    TreeNode* right;

    TreeNode(int val){
        this->val=val;
        left=NULL;
        right=NULL;
    }

}

TreeNode* buildTree(){

    int data;
    cout<< "enter the val of node: "<<endl;
    cin>>data;
    if(data==-1){
        return NULL;
    }

    TreeNode* root=new TreeNode(data);

    cout<<"enter the val of left side of "<<data<<endl;
    root->left=buildTree();
    cout<<"enter the val of right side of "<<data<<endl;
    root->right=buildTree();
    return root;

}

int height(TreeNode* root){
    if(root==NULL){
        return 0;
    }
    int leftVal=height(root->left);
    int rightVal=height(root->right);

    int finalVal=1+max(leftVal,rightVal);
    return finalVal;
}

void inOrderTraversal(TreeNode* root){
    queue<TreeNode*> q;
    q.push(root);
    q.push(NULL);
    while(!q.empty()){
        TreeNode* temp=q.front();
        q.pop();
        // NULL POINER EXCEPTION IS COME
        if(temp==NULL){
            cout<<endl;
            if(!q.empty()){
                q.push(NULL);
            }
        }
        else{
            cout<<temp->val<<" ";
            if(temp->left){
                q.push(temp->left);
            }
            if(temp->right){
                q.push(temp->right);
            }
        }
    }


}
void postOrder(TreeNode* root){
    if(root==NULL) return;

    postOrder(root->left);
    postOrder(root->right);
    cout<<root->val<<" ";
}

void inOrder(TreeNode* root){
    if(root==NULL) return;

    inOrder(root->left);
    cout<<root->val<<" ";
    inOrder(root->right);
    
}

void preOrder(TreeNode* root){
    if(root==NULL) return;

    cout<<root->val<<" ";
    preOrder(root->left);
    preOrder(root->right);
    
}

int main(){
    TreeNode* root=NULL;
    root=buildTree();
    int ans=height(root);
    cout<<ans<<endl;
    inOrderTraversal(root);
    preOrder(root);
    inOrder(root);
    postOrder(root);
}