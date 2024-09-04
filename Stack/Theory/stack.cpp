#include<iostream>
using namespace std;
class Stack{

    public:
    int *arr;
    int top;
    int size;
    
    Stack(int size){
        this->size=size;
        arr=new int[size];
        top=-1;
    }

    void push(int data){
        if(top==size-1){
        cout<<"overFlow"<<endl;
         return ;
        }
        top=top+1;
        arr[top]=data;
    }

    void pop(){
        if(top==-1)
        cout<<"stack underflow"<<endl;
        arr[top]=0;
        top--;
    }

    int Top(){
        if(top==-1){
            cout<<"stack is empty"<<endl;
            return -1;
        }
        return arr[top];
    }

    int getSize(){
        return top+1;
    }

    bool isEmpty(){
        if(top==-1)
        return 1;
        return 0;
    }
};



int main(){
    Stack st(10);
    st.push(10);
    st.push(20);
    st.push(30);
    st.push(40);
    st.push(50);
    st.push(60);
    st.push(70);
    st.push(80);
    st.push(90);
    st.push(100);
    while(!st.isEmpty()){
        cout<<st.Top()<<" ";
        st.pop();
    }
    
    return 0;
}