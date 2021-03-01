#include <bits/stdc++.h>
using namespace std;

class MinStack{
    stack<int>s,ss;
    public:
    void push(int ele){
        s.push(ele);
        if(ss.empty()){
            ss.push(ele);
            return;
            }
        if(ss.top()>ele)ss.push(ele);
    }
    void pop(){
        if(s.top()==ss.top())ss.pop();
        s.pop();
    }
    int minEle(){
        return ss.top();
    }int top(){
        return s.top();
    }bool empty(){
        return s.empty();
    }
};

int main() {
    MinStack s;

    s.push(18);
    s.push(19);
    s.push(29);
    s.push(15);
    s.push(16);

    while(!s.empty()){
        cout<<s.top()<<":"<<s.minEle()<<"\t";
        s.pop();
    }

    return 0;
}
