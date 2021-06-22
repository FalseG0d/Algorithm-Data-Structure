#include <iostream>
using namespace std;
int main() {
    int arr[]={20,17,15,14,13,12,10,9,8,4};
    int target;

    cin>>target;

    int beg=0;
    int end=sizeof(arr)/sizeof(int);

    while(beg<end){
        int mid=beg+(end-beg)/2;

        if(arr[mid]>target)beg=mid+1;
        else if(arr[mid]<target)end=mid-1;
        else {
            cout<<mid+1;
            break;
            }
    }

    return 0;
}
