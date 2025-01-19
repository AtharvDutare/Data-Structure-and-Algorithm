//time complexity=O(n+m) where n and m are the number of nodes in the two linked lists
//space complexity=O(1)
// two pointer approach is used to merge the two linked lists

/* Link list Node
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
    Node* sortedMerge(Node* head1, Node* head2) {
        // code here
        Node* head=new Node(-1);
        Node* ans=head;
        while(head1&&head2) {
            if(head1->data<=head2->data) {
                head->next=head1;
                head=head1;
                head1=head1->next;
                head->next=NULL;
            }
            else {
                head->next=head2;
                head=head2;
                head2=head2->next;
                head->next=NULL;
            }
        }
        while(head1) {
            head->next=head1;
            head=head1;
            head1=head1->next;
            head->next=NULL;
        }
        while(head2) {
            head->next=head2;
            head=head2;
            head2=head2->next;
            head->next=NULL;
        }
        return ans->next;
    }
};