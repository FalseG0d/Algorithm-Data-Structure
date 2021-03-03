#include <bits/stdc++.h>
using namespace std;

void insertAtBottom(stack<int>&s,int val){
    if(s.size()==0){
        s.push(val);
        return;
    }else{
        int top=s.top();
        s.pop();
        insertAtBottom(s,val);
        s.push(top);
    }
}

void reverse(stack<int>&s){
    if(s.size()==0)return;

    int top=s.top();
    s.pop();
    reverse(s);

    insertAtBottom(s,top);
}

int main() {
    stack<int>s;

    s.push(10);
    s.push(4);
    s.push(30);
    s.push(6);
    s.push(1);

    reverse(s);

    while(!s.empty()){
        cout<<s.top()<<" ";
        s.pop();
    }

    return 0;
}
