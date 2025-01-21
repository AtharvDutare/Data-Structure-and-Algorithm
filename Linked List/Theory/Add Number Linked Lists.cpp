// time complexity O(n+m)
// space complexity O(1)

/* node for linked list:

struct Node {
    int data;
    struct Node* next;
    Node(int x) {
        data = x;
        next = NULL;
    }
};

*/

class Solution {
    private:
    int nodeLength(Node* head) {
        int ans=0;
        while(head) {
            head=head->next;
            ans++;
        }
        return ans;
    }
    
    Node* addZeroFromFront(Node* head,int len,int maxLength) {
        int diff=maxLength-len;
        while(diff--) { 
            Node* temp=new Node(0);
            temp->next=head;
            head=temp;
        }
        return head;
    }
    
    Node* reverseLL(Node* head) {
        if(!head) {
            return NULL;
        }
        Node* ans=NULL;
        while(head) {
            Node* temp=head->next;
            head->next=ans;
            ans=head;
            head=temp;
        }
        return ans;
    } 

    void print(Node* head) {
        if(!head) {
            cout<<"empty"<<endl;
            return;
        }
        while(head) {
            cout<<head->data<<endl;
            head=head->next;
        }
        
    }
    
    
  public:
    Node* addTwoLists(Node* num1, Node* num2) {
        int n=nodeLength(num1);
        int m=nodeLength(num2);
        int maxLength=max(n,m);
        if(n!=maxLength) {
            num1=addZeroFromFront(num1,n,maxLength);
        }
        if(m!=maxLength) {
            num2=addZeroFromFront(num2,m,maxLength);
        }
        
        // print(num1);
        // print(num2);
        num1=reverseLL(num1);
        num2=reverseLL(num2);
        
        int carry=0;
        int i=0;
        Node* ans=NULL;
        while(i<maxLength&&num1&&num2) {
            int sum=num1->data+num2->data+carry;
            carry=0;
            int d=sum%10;
            int r=sum/10;
            carry=r;
            
            Node* newNode=new Node(d);
            
            newNode->next=ans;
            ans=newNode;
            
            num1=num1->next;
            num2=num2->next;
            i++;
        }
        
        if(carry) {
            Node* newNode=new Node(carry);
            newNode->next=ans;
            ans=newNode;
        }
        while(ans->data==0) {
            ans=ans->next;
        }
        return ans;
        
        
    }
};