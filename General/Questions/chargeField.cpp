#include <iostream>
using namespace std;

int chargeField(int arr[],char*ch,int n){
    int s=0;

    for(int i=0;i<n;i++){
        if(ch[i]=='P'){
            s+=arr[i];
        }else{
            s-=arr[i];
        }
    }

    return s>0?s*100:s*-100;
}

int main() {
    int arr[]={4,3,5};
    char ch[]={'P','N','P'};
    int n=3;

    cout<<chargeField(arr,ch,n);
}
