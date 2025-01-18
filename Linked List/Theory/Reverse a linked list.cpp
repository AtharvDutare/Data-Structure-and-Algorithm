//time complexity=O(n) and space complexity=O(1)
class Solution {
  public:
    Node* reverseList(struct Node* head) {
        // code here
        if(!head) {
            return NULL;
        }
        Node* ans=NULL;
        while(head!=NULL) {
            Node* temp=head->next;
            head->next=ans;
            ans=head;
            head=temp;
        }
        return ans;
        
        
    }
};