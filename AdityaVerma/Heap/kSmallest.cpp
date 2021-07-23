#include <bits/stdc++.h>
using namespace std;

int kSmallest(vector<int>v,int k){
    priority_queue<int>pq;

    int n=v.size();
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

    cout<<kSmallest(v,k);

    return 0;
}
