#include<bits/stdc++.h> 
using namespace std; 

/*
Time Complexity:
	Best Case:		O(n*log(n))
	Average Case:	O(n*log(n))
	Worst Case:		O(n^2)
*/

//Takes a Constant amount of Extra Memory Unlike Mergesort

void swap(int* a, int* b)  
{  
    int t = *a;  
    *a = *b;  
    *b = t;  
}

int partition(int arr[],int l,int h){
	int pivot=arr[h];
	
	int i=(l-1);
	
	for(int j=l;j<=h-1;j++){
		if(arr[j]<pivot){
			i++;
			swap(&arr[j],&arr[i]);
		}
	}
	swap(&arr[i+1],&arr[h]);
	return i+1;
}

void quickSort(int arr[],int l,int h){
	if(l<h){
		int pi=partition(arr,l,h);
		quickSort(arr,l,pi-1);
		quickSort(arr,pi+1,h);
	}
}

void printArray(int A[], int size)
{
	for (int i = 0; i < size; i++)
		cout << A[i] << " ";
}

int main()
{
	int arr[] = {9,8,7,6,5,4,3,2,1};
	int arr_size = sizeof(arr) / sizeof(arr[0]);

	quickSort(arr, 0, arr_size - 1);

	printArray(arr, arr_size);
	return 0;
}