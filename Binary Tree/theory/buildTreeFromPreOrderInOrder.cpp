int findPosition(int arr[],int n,int element) {
    for(int i=0;i<n;i++) {
        if(arr[i]==element) {
            return i;
        }
    }
    return -1;
}

Node* buildTreeFromPreOrderInOrder(int inorder[],int preorder[],int size,int &preIndex,int inorderStart,int inorderEnd) {
    //base case
    if(preIndex>=size||inorderStart>inorderEnd) {
        return NULL;
    }
    int element=preorder[preIndex++];
    Node* root=new Node(element);
    int pos =findPosition(inorder,size,element);

    root->left=buildTreeFromPreOrderInOrder(inorder,preorder,size,preIndex,inorderStart,pos-1);

    root->right=buildTreeFromPreOrderInOrder(inorder,preorder,size,preIndex,pos+1,inorderEnd);
    return root;
}