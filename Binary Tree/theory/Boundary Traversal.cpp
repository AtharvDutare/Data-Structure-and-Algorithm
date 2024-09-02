void printLeftBoundary(Node* root) {
    //base case
    if(!root) {
        return NULL;
    }
    if(root->left==NULL||root->right==NULL) {
        return;
    }
    cout<<root->data<<" ";
    if(root->left) {
        printLeftBoundary(root->left);
    }
    else{
        printLeftBoundary(root->right);
    }
}

void printLeafBoundary(Node* root) {
    if(!root) {
        return;
    }
    if(root->left==NULL&&root->right==NULL) {
        cout<<root->data<<" ";
    }
    printLeafBoundary(root->left);
    printLeafBoundary(root->right);
}

void printRightBoundary(Node* root) {
    if(!root) {
        return;
    }
    if(root->left==NULL&&root->right==NULL) {
        return;
    }
    if(root->right) {
        printRightBoundary(root->right);
    }
    else{
        printRightBoundary(root->left);
    }
    cout<<"root->data"<<" "; 
}

void boundaryTraversal(Node* root) {
    if(!root) {
        return ;
    }
    cout<<root->data<<endl;
    //A
    printLeftNode(root->left);
    //B
    printLeafNode(root);
    //C
    printRightNode(root->right);
}