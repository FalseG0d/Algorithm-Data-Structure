#include <iostream>
using namespace std;

struct Node{
    int val;
    Node*next;
};

class Stack{
    Node*top;
    public:
    Stack(){
        top=NULL;
    }
    void push(int val){
        Node*temp=new Node();
        if(temp==NULL){
            cout<<"\nOver Flow";
            return;
        }
        temp->val=val;
        temp->next=NULL;
        if(top==NULL){
            top=temp;
            return;
        }
        temp->next=top;
        top=temp;
    }
    int pop(){
        if(top==NULL){
            cout<<"\nUnder Flow";
            return 0;
        }
        Node*temp=top;
        int ret=temp->val;
        top=top->next;

        delete temp;

        return ret;
    }

    void print(){
        Node*temp=top;

        while(temp!=NULL){
            cout<<temp->val<<"-->";
            temp=temp->next;
        }cout<<"\n";

        return;
    }
};

int main() {
    Stack s;

    s.push(1);
    s.push(2);
    s.push(3);
    s.push(4);
    s.push(5);

    s.print();

    cout<<s.pop()<<"\n";

    s.print();
    return 0;
}
