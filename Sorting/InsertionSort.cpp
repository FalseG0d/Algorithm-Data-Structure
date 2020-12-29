#include<bits/stdc++.h> 
using namespace std; 

/*
Time Complexity:
	Best Case:		O(n)
	Average Case:	O(n^2)
	Worst Case:		O(n^2)
*/

void insertionSort(int arr[],int n){
	for(int i=0;i<n;i++){
		int val=arr[i];
		int hole=i;
		while(hole>0&&arr[hole-1]>val){
			arr[hole]=arr[hole-1];
			hole--;
		}
		arr[hole]=val;
	}
    for(int i=0;i<n;i++){
		cout<<arr[i]<<" ";
	}
}

int main(){
	int arr[]={9,8,7,6,5,4,3,2,1};
	
	insertionSort(arr,9);
	
	return 0;
}