#include<bits/stdc++.h>
using namespace std;

int main(){
    int n;
    cin>>n;
    
    int*arr=new int[n];
    for(int i=0;i<n;i++) cin>>arr[i];
    
    int k;
    cin>>k;
    
    priority_queue<int,vector<int>,greater<int>>pq(arr,arr+n);
    
    int itr=0;
    
    while(itr<n-k){
        pq.pop();
        itr++;
    }
    
    while(!pq.empty()){
        cout<<pq.top()<<"\n";
        pq.pop();
    }
    
    return 0;
}