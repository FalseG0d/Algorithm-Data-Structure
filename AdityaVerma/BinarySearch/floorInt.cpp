#include <iostream>
using namespace std;

int main() {
    int arr[] =  {1,2,3,4,8,10,10,12,19};
    int key = 18;

    int n=sizeof(arr)/sizeof(int);

    int beg=0;
    int end=n-1;

    int mid=beg+(end-beg)/2;;

    int res=-1;

    while(beg<end){       
        if(arr[mid]==key)break;
        else if(arr[mid]<key)beg=mid;
        else end=mid;

        if(res==arr[mid])break;

        res=arr[mid];

        mid=beg+(end-beg)/2;
    }

    cout<<arr[mid];

    return 0;
}
