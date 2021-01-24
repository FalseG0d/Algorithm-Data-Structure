#include <bits/stdc++.h>
using namespace std;

//int arr[100];

int fibo(int n,int arr[]){
    if(arr[n]==-1){
        arr[n]=fibo(n-1,arr)+fibo(n-2,arr);
    }
    return arr[n];
}

int main(){
    int n;
    cin>>n;
	
	int*arr=new int[n];

    for(int i=0;i<100;i++){
        arr[i]=-1;
    }
    
    arr[0]=0;
    arr[1]=1;
    
    fibo(n,arr);

    for(int i=0;i<=n;i++){
        cout<<arr[i]<<" ";
    }

    return 0;
}