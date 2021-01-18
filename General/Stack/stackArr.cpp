#include <iostream>
using namespace std;

class Stack{
    int arr[100];
    int top;
    int size;
    public:
    Stack(){
        top=-1;
        size=100;
    }
    void push(int ele){
        if(top==-1){
            top=0;
            arr[top]=ele;
            return;
        }
        if(top>=size-1){
            cout<<"\nOver Flow";
            return;
        }

        arr[++top]=ele;
    }
    int pop(){
        if(top==-1){
            cout<<"\nUnder Flow";
            return 0;
        }
        return arr[top--];
    }
    void print(){
        for(int i=top;i>=0;i--){
            cout<<arr[i]<<" ";
        }cout<<"\n";
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
