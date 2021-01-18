#include <iostream>
using namespace std;
int main() {
    int arr[100];
    int len;
    cin>>len;

    for(int i=0;i<len;i++){
        cin>>arr[i];
    }

    for(int i=0;i<len-1;i++){
        for(int j=i+1;j<len;j++){
            if((arr[i]>0&&arr[j]<=0)||(arr[i]>=0&&arr[j]<0)){
                int temp=arr[i];
                arr[i]=arr[j];
                arr[j]=temp;
            }
        }
    }

    for(int i=0;i<len;i++){
        cout<<arr[i]<<" ";
    }

    return 0;
}
