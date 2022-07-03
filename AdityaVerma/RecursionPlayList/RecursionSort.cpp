#include <iostream>
using namespace std;

void sort(int*arr, int pos, int N){
    if(pos >= N) return;

    sort(arr, pos+1, N);

    int val = arr[pos];

    int itr = pos + 1;
    while(itr < N && val > arr[itr]){
        arr[itr-1] = arr[itr];
        itr++; 
    }

    arr[itr-1] = val;
}

int main() {
    int arr[] = {9,8,7,6,5,4,3,2,1};
    int N = 9;

    sort(arr, 0, N);

    for(int i=0;i<N;i++) cout<<arr[i]<<" ";

    return 0;
}
