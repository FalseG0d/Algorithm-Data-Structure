#include <iostream>
using namespace std;

struct node{
    int val;
    node*next;
};

class Stack{
    node*top;
    int size;
    public:
    Stack(){
        size=0;
        top=NULL;
    }
    void push(int val){
        node*temp=new node();
        if(temp==NULL){
            cout<<"Overflow";return;
        }size++;
        temp->val=val;
        temp->next=NULL;

        if(top==NULL)top=temp;
        else{
            temp->next=top;
            top=temp;
        }
    }
    void pop(){
        if(top==NULL){
            cout<<"Undeflow";return;
        }size--;
        node*temp=top;
        top=top->next;
        delete temp;
    }
    int getSize(){
        return size;
    }
    void print(){
        node*temp=top;
        while(temp!=NULL){
            cout<<temp->val<<" ";
            temp=temp->next;
        }cout<<"\n";
    }
    void delete_Middle(int size){
        if(size==0){
            pop();
            return;
            }
        int val=top->val;
        pop();
        delete_Middle(size-1);
        push(val);
    }
};

int main(){
    Stack s;

    s.push(10);
    s.push(4);
    s.push(30);
    s.push(6);
    s.push(1);

    int size=s.getSize();

    if(size%2==1)
        s.delete_Middle(size/2);
    else{
        s.delete_Middle(size/2);
        s.delete_Middle(size/2-1);
    }

    s.print();

    return 0;
}