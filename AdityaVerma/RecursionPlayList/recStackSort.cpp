#include <iostream>
using namespace std;

struct node{
    int val;
    node*next;
};

class Stack{
    node*top;
    public:
    Stack(){
        top=NULL;
    }
    void push(int val){
        node*temp=new node();
        if(temp==NULL){
            cout<<"Overflow";return;
        }
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
        }
        node*temp=top;
        top=top->next;
        delete temp;
    }
    void print(){
        node*temp=top;
        while(temp!=NULL){
            cout<<temp->val<<" ";
            temp=temp->next;
        }cout<<"\n";
    }

    void recSort(int val){
        // print();
        if(top==NULL){
            push(val);return;
            }

        push(val);
        node*temp=top;

        while(temp->next!=NULL){
            node*next=temp->next;
            
            if(next->val<temp->val){
                int val=next->val;
                next->val=temp->val;
                temp->val=val;
            }

            temp=temp->next;
        }
    }

    void sort(){
        // print();
        if(top==NULL)return;

        int a=top->val;

        pop();
        sort();
        recSort(a);
    }
};

int main(){
    Stack s;

    s.push(10);
    s.push(4);
    s.push(30);
    s.push(6);
    s.push(1);

    s.sort();
    s.print();

    return 0;
}