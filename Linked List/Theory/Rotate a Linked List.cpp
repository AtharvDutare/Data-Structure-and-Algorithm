//time complexity=O(n) and space complexity=O(1)
/*
struct Node {
    int data;
    struct Node *next;
    Node(int x) {
        data = x;
        next = NULL;
    }
};

*/

class Solution {
  public:
    int NodeLength(Node* head) {
        int ans=0;
        while(head) {
            ans++;
            head=head->next;
        }
        return ans;
    }
  
    Node* rotate(Node* head, int k) {
        // Your code here
        int n=NodeLength(head);
        k=k%n;
        Node* tail=NULL;
        Node* trav=head;
        while(trav->next) {
            trav=trav->next;
        }
        tail=trav;
        while(k--) {
            Node* temp=head->next;
            tail->next=head;
            tail=head;
            head->next=NULL;
            head=temp;
        }
        return head;
    }
};