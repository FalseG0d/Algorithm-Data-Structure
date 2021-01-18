#include <iostream>
using namespace std;
int main() {
    int arr[100];
    int len;
    cin>>len;

    for(int i=0;i<len;i++){
        cin>>arr[i];
    }

    int ptr=0;
    for(int i=0;i<len;i++){
        if(arr[i]<0&&ptr!=i){
            int temp=arr[i];
            arr[i]=arr[ptr];
            arr[ptr]=temp;
            ptr++;
        }
    }

    for(int i=0;i<len;i++){
        cout<<arr[i]<<" ";
    }

    return 0;
}
