#include<iostream>
using namespace std;
struct node *temp;

struct node{
    int data;
    struct node *next;
};

void linkedListIn(struct node *ptr){
    struct node *start;
    start =ptr;

    while(start!=nullptr){
        cin>>start->data;
        start=start->next;
    }

}

void traversal(struct node *ptr){

  struct node *start;
  start=ptr;
  
  while(start!=nullptr){
        cout<<start->data<<endl;
        start=start->next;
    }

}

int counting(struct node *ptr){
    int count =0;
    while(ptr!=nullptr){
        count++;
        ptr=ptr->next;
    }
    return count;
}

void checkLastSecond(const struct node *ptr){
        if (ptr==nullptr||ptr->next==nullptr){
        cout <<"size of linkedList is less than 2 "<<endl;
        return;
        }

        while(ptr->next->next!=nullptr){
            ptr=ptr->next;
        }
        cout<<ptr->data<<endl;
}

bool searchKey(struct node *ptr,int key){
    while(ptr!=nullptr){
           if(ptr->data==key){
                return true;
           }
           ptr=ptr->next;
        }
        return false;
}


    void insertAtBegin(struct node *ptr,int key){
   

    temp->next=ptr;
    temp->data=key;
    ptr=temp;
    }
    void deletionAtBegin(struct node *ptr){
        
        ptr->next
    }

    




int main (){
    
   
    struct node s1,s2,s3;
    struct node *start=&s1;
    // start->data=10;
    s1.next =&s2;
    s2.next=&s3;
    s3.next=nullptr;
    

    linkedListIn(start);
    // cout<<endl;
    // traversal(start);
    // cout<<endl;
    // cout<<counting(start)<<endl;

    // checkLastSecond(start);
    traversal(start);
    
    insertAtBegin(start,5);

    traversal(start);
    return 0;
}