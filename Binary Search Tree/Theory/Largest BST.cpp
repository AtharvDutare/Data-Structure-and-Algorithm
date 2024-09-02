/* Tree node structure  used in the program

struct Node {
    int data;
    Node *left;
    Node *right;

    Node(int val) {
        data = val;
        left = right = NULL;
    }
};*/
class NodeValue{
    public:
    int maxValue,minValue,size;
    NodeValue(int maxValue,int minValue,int size) {
        this->maxValue=maxValue;
        this->minValue=minValue;
        this->size=size;
    }
};
class Solution{
    public:
    /*You are required to complete this method */
    // Return the size of the largest sub-tree which is also a BST
    NodeValue* solve(Node* root) {
        if(!root) return new NodeValue(INT_MIN,INT_MAX,0);
        NodeValue* left=solve(root->left);
        NodeValue* right=solve(root->right);
        if(left->maxValue<root->data&&root->data<right->minValue) {
            return new NodeValue(max(root->data,right->maxValue),min(root->data,left->minValue),left->size+right->size+1);
        }
        return new NodeValue(INT_MAX,INT_MIN,max(left->size,right->size));
    }
    
    int largestBst(Node *root)
    {
    	NodeValue* node=solve(root);
    	return node->size;
    }
};