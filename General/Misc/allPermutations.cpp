#include <bits/stdc++.h>
using namespace std;

void printArray(int arr[],int n){
    for(int i=0;i<n;i++){
        cout<<arr[i]<<" ";
    }cout<<"\n";
}

void permutation(int arr[],int cid,int n){
    if(cid==n-1){
        printArray(arr,n);
        return;
    }
    for(int i=cid;i<n;i++){
        swap(arr[i],arr[1+cid]);
        permutation(arr,cid+1,n);
        swap(arr[i],arr[1+cid]);
    }
}

int main() {
    int arr[]={1,2,3};
    permutation(arr,0,3);
}
