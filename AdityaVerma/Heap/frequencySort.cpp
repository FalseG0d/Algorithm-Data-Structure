#include <bits/stdc++.h>
using namespace std;

typedef pair<int,int>pp;

void printFreqSort(int*arr,int n){
    map<int,int>mp;

    for(int i=0;i<n;i++) mp[arr[i]]++;

    priority_queue<pp>pq;

    for(auto itr:mp){
        pq.push({itr.second,itr.first});
    }

    while(!pq.empty()){
        pp temp=pq.top();

        for(int i=0;i<temp.first;i++)cout<<temp.second<<" ";
        // cout<<temp.first<<" ";
        pq.pop();
    }
}

int main() {
    int n;
    cin>>n;

    int*arr=new int[n];
    for(int i=0;i<n;i++)cin>>arr[i];

    printFreqSort(arr,n);

    return 0;
}
