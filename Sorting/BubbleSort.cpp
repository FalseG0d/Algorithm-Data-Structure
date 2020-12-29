#include<bits/stdc++.h> 
using namespace std; 

/*
Time Complexity:
	Best Case:		O(n)
	Average Case:	O(n^2)
	Worst Case:		O(n^2)
*/

void bubbleSort(int arr[],int n){
	for(int i=0;i<n-1;i++){
		for(int j=0;j<n-i-1;j++){
			if(arr[j]<arr[i]){
				int temp=arr[i];
				arr[i]=arr[j];
				arr[j]=temp;
			}
		}
	}
    for(int i=0;i<n;i++){
		cout<<arr[i]<<" ";
	}
}

int main(){
	int arr[]={9,8,7,6,5,4,3,2,1};
	
	bubbleSort(arr,9);
	
	return 0;
}