#include <bits/stdc++.h>
using namespace std;

int nearestGreaterToRight(int arr[],int n){
   for(int i=0;i<n-1;i++){
       for(int j=i+1;j<n;j++){
           if(arr[j]>arr[i]){
               cout<<arr[j]<<" ";
               break;
           }
       }
   } 

    return -1;
}

int main() {
    int n;
    cin>>n;
    int*arr=new int[n];
    for(int i=0;i<n;i++){
        cin>>arr[i];
    }

    cout<<nearestGreaterToRight(arr,n);
    
    return 0;
}