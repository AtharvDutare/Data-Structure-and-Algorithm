Node* buildTreeFromPostOrderInOrder(int inorder[],int postorder[],itn &postIndex,int size,int inorderStart,int inorderEnd,unordered_map<int,int>&mapping){
    //base case
    if(postIndex<0||inorderStart>inorderEnd) {
        return NULL;
    }
    int element=postorder[postIndex--];
    Node* root=new Node(element);
    int pos=mapping[element];

    //root->right solve
    root->right=buildTreeFromPostOrderInOrder(inorder,postorder,postIndex,size,pos=1,inorderEnd,mapping);

    //root->left solve
    root->left=buildTreeFromPostOrderInOrder(inorder,postorder,postIndex,size,inorderStart,pos-1,mapping);

    return root;
}