#include <bits/stdc++.h>
using namespace std;

stack<int> getStack(int arr[], int N){
    stack<int>s;

    for(int i=N-1;i>=0;i--) s.push(arr[i]);
    // for(int i=0;i<N;i++) s.push(arr[i]);

    return s;
}

void print(stack<int>s){
    while(!s.empty()){
        cout<<s.top()<<" ";
        s.pop();
    }
}

stack<int> sort(stack<int>s){
    if(s.empty()) return s;

    int val = s.top();
    s.pop();

    stack<int>sorted = sort(s);
    stack<int>aux;

    while(!sorted.empty() && val > sorted.top()){
        aux.push(sorted.top());
        sorted.pop();
    }
    sorted.push(val);
    while(!aux.empty()){
        sorted.push(aux.top());
        aux.pop();
    }

    return sorted;
}

int main() {
    int arr[] = {9,0,7,4,5,4,3,1,1};
    stack<int> s = getStack(arr, 9);

    s = sort(s);    

    while(!s.empty()){
        cout<<s.top()<<" ";
        s.pop();
    }

    return 0;
}