#include <iostream>
using namespace std;

int main() {
    int arr[] =  {10, 3, 40, 20, 50, 80, 70};
    int key = 40;

    int res=-1;
    int n=sizeof(arr)/sizeof(int);

    int beg=0;
    int end=n-1;

    while(beg<end){
        int mid=beg+(end-beg)/2;

        if(arr[mid]==key){
            res=mid;break;
        }else if(arr[(mid+1)%n]){
            res=(mid-1)%n;break;
        }else if(arr[(mid-1+n)%n]){
            res=(mid-1+n)%n;break;
        }

        if(arr[mid]<key)end=mid-2;
        else beg=mid+2;
    }

    cout<<res;

    return 0;
}
