#include <bits/stdc++.h>
using namespace std;

int minKElement(vector<int>v,int k){
    int n=v.size();
    priority_queue<int,vector<int>,greater<int>>pq;

    for(int i=0;i<n;i++){
        pq.push(v[i]);
        if(pq.size()>k)pq.pop();
    }

    return pq.top();
}

int main() {
    int n;
    cin>>n;

    vector<int>v(n);
    for(int i=0;i<n;i++)cin>>v[i];

    int k;
    cin>>k;

    cout<<minKElement(v,k);

    return 0;
}
