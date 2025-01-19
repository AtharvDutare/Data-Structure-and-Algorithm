#include <bits/stdc++.h> 
using namespace std;
/*************************************************
        Following is the structure of class Node:
     
        class Node{
        public:
            int data;
            Node* next;
            
            Node(int data){
                this->data = data;
                this->next = NULL;
            }
            
        }
**************************************************/

bool isCircular(Node* head){
    if(head==NULL){
        return true;
    }
    Node*slow =head;
    Node *fast=head;
    while(fast!=NULL){
        fast=fast->next;
        if(fast!=NULL){
            fast=fast->next;
            slow=slow->next;
        }
        if(slow ==fast){
            break;
        }
       
    }
    return slow==fast && slow==head;
}