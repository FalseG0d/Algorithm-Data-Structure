#include <bits/stdc++.h>
using namespace std;

class MinStack{
    stack<int>s;
    int minEle=-1;
    public:
    void pop(){
        if(s.size()==1){
            minEle=-1;
            s.pop();
            return;
        }
        if(s.top()<minEle){
            minEle=2*minEle-s.top();
        }
        s.pop();
    }
    void push(int ele){
        if(s.empty()){
            minEle=ele;
            s.push(ele);
            return;
        }
        if(minEle>ele){
            s.push(2*ele-minEle);
            minEle=ele;
        }else{
            s.push(ele);
        }
    }
    int peek(){
        if(!s.empty()){
            if(s.top()<minEle)return 2*minEle-s.top();
            else return s.top();
        }else return -1;
    }
    int getMin(){
        return minEle;
    }
    bool empty(){
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
        cout<<s.peek()<<":"<<s.getMin()<<"\t";
        s.pop();
    }

    return 0;
}
