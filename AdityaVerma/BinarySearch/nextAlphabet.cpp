#include <iostream>
using namespace std;

int main() {
    char arr[] =  {'a','c','f','h'};
    char key = 'g';

    int n=sizeof(arr)/sizeof(char);

    int beg=0;
    int end=n-1;

    int mid;

    while(beg<end){
        mid=beg+(end-beg)/2;

        if(key==arr[mid])break;
        else if(key>arr[mid])beg=mid+1;
        else end=mid-1;
    }

    cout<<arr[mid+1];

    return 0;
}
