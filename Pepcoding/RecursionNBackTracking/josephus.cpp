#include<bits/stdc++.h>
using namespace std;

int josephus(queue<int>circle,int n,int k){
    if(n==1)return circle.front();

    for(int i=0;i<k-1;i++){
        circle.push(circle.front());
        circle.pop();
    }

    // cout<<circle.front()<<" ";
    circle.pop();
    n--;

    return josephus(circle,n,k);
}

int main(){
    int n,k;
    cin>>n>>k;

    queue<int>circle;

    for(int i=0;i<n;i++)circle.push(i);

    cout<<josephus(circle,n,k);

    return 0;
}