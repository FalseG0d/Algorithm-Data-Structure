#include <iostream>
using namespace std;
int main() {
    int arr[100];
    int len;
    cin>>len;

    for(int i=0;i<len;i++){
        cin>>arr[i];
    }

    for(int i=0;i<len/2;i++){
        int temp=arr[i];
        arr[i]=arr[len-i-1];
        arr[len-i-1]=temp;
    }

    for(int i=0;i<len;i++){
        cout<<arr[i]<<" ";
    }

    return 0;
}
