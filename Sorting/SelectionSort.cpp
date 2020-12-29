#include<bits/stdc++.h> 
using namespace std; 

void selectionSort(int arr[],int n){
    // int n=sizeof(*arr)/sizeof(int);
	int p;
	for(int i=0;i<n-1;i++){
		int min=1000;
		for(int j=i;j<n;j++){
			if(min>arr[j]){
				min=arr[j];
				p=j;
			}
		}
		int temp=arr[i];
		arr[i]=min;
		arr[p]=temp;
	}
    for(int i=0;i<n;i++){
		cout<<arr[i]<<" ";
	}
}

int main(){
	int arr[]={9,8,7,6,5,4,3,2,1};
	
	selectionSort(arr,9);
	
	return 0;
}