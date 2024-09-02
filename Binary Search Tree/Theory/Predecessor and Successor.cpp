/* BST Node
struct Node
{
	int key;
	struct Node *left;
	struct Node *right;
	
	Node(int x){
	    key = x;
	    left = NULL;
	    right = NULL;
	}
};
*/

// This function finds predecessor and successor of key in BST.
// It sets pre and suc as predecessor and successor respectively
class Solution
{
    public:
    
    void inorder(Node *root,vector<int> &temp){
        if(root==NULL) return;
        inorder(root->left,temp);
        temp.push_back(root->key);
        inorder(root->right,temp);
    }
    
    Node* binarySearch(Node* root,int key){
        if(root==NULL) return NULL;
        if(root->key==key) return root;
        if(root->key<key) binarySearch(root->right,key);
        else binarySearch(root->left,key);
    }
    
    
    void findPreSuc(Node* root, Node*& pre, Node*& suc, int key)
    {
        vector<int> temp;
        inorder(root,temp);
        int index1=lower_bound(temp.begin(),temp.end(),key)-temp.begin()-1;
        int index2=upper_bound(temp.begin(),temp.end(),key)-temp.begin();
        pre=binarySearch(root,temp[index1]);
        suc=binarySearch(root,temp[index2]);
        
    }
};

/* BST Node
struct Node
{
	int key;
	struct Node *left;
	struct Node *right;
	
	Node(int x){
	    key = x;
	    left = NULL;
	    right = NULL;
	}
};
*/

// This function finds predecessor and successor of key in BST.
// It sets pre and suc as predecessor and successor respectively
class Solution
{
    public:
    
    void inorder(Node* root, Node*& pre, Node*& suc, int key,bool &flag){
        if(root==NULL) return;
        inorder(root->left,pre,suc,key,flag);
        if(root->key<key){
            pre=root;
        }
        if(root->key>key&& flag){
            suc=root;
            flag=false;
            return;
        }
        inorder(root->right,pre,suc,key,flag);
    }
    
    void findPreSuc(Node* root, Node*& pre, Node*& suc, int key)
    {
        bool flag=true;
        inorder(root,pre,suc,key,flag);
    }
};
