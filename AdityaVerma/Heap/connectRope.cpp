#include <bits/stdc++.h>
using namespace std;

int connectRopes(int*arr,int n){
    priority_queue<int,vector<int>,greater<int>>pq;

    for(int i=0;i<n;i++)pq.push(arr[i]);

    int res=0;

    while(!pq.empty()){
        if(pq.size()==1) break;
        int p1=0;
        int p2=0;

        if(!pq.empty()) {p1=pq.top();pq.pop();}
        if(!pq.empty()) {p2=pq.top();pq.pop();}

        res+=(p1+p2);

        pq.push(p1+p2);
    }

    return res;
}

int main() {
    int n;
    cin>>n;

    int*arr=new int[n];

    for(int i=0;i<n;i++)cin>>arr[i];

    cout<<connectRopes(arr,n);

    return 0;
}
