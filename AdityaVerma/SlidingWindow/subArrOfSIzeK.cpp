#include <bits/stdc++.h>
using namespace std;

void print(queue<int> que){
    while(!que.empty()){
        cout<<que.front()<<" ";
        que.pop();
    }cout<<"\n";
}

void subArrOfSizeK(int arr[],int k,int n){
    queue<int> que;

    for(int i=0;i<n;i++){
        que.push(arr[i]);
        if(i+1>=4){
            print(que);
            que.pop();
        }
    }
}

int main() {
    int t;
    cin>>t;

    while(t--){
        int n;
        cin>>n;

        int*arr=new int[n];

        for(int i=0;i<n;i++)cin>>arr[i];

        int k;
        cin>>k;

        subArrOfSizeK(arr,k,n);
    }

    return 0;
}
