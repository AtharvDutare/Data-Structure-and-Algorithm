/*
  Node is defined as
    struct node
    {
        int data;
        struct Node* next;

        Node(int x){
            data = x;
            next = NULL;
        }

    }*head;
*/

//my approach
//reverse the first k nodes and then recursively call the function for the next k nodes
//time complexity O(n) and space complexity O(1)
// recursive stack space O(n/k)

class Solution {
  public:
    Node *reverseKGroup(Node *head, int k) {
        // code here
        if(!head) {
            return NULL;
        }
        Node* tail=head;
        int t=k;
        while(t--&&tail) {
            tail=tail->next;
        }
        Node* ans=NULL;
        Node* trav=head;
        while(trav!=tail) {
            Node* temp=trav->next;;
            trav->next=ans;
            ans=trav;  
            trav=temp;
        }
        head->next=reverseKGroup(tail,k);
        return ans;
    }
};