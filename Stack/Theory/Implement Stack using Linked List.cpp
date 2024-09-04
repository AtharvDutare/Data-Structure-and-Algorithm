class MyStack {
  private:
    StackNode *top;

  public:
    void push(int x) {
        StackNode* t=new StackNode(x);
        t->next=top;
        top=t;
    }

    int pop() {
        if(!top) return -1;
        int t=top->data;
        top=top->next;
        return t;
    }

    MyStack() { top = NULL; }
};