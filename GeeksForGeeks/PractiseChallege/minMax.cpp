#include <bits/stdc++.h>
using namespace std;
int main() {
    int arr[100];
    int len;
    cin>>len;

    for(int i=0;i<len;i++){
        cin>>arr[i];
    }

    int min=INT_MAX,max=INT_MIN;

    for(int i=0;i<len;i++){
        if(arr[i]>max){
            max=arr[i];
        }if(arr[i]<min){
            min=arr[i];
        }
    }

    cout<<"Max: "<<max<<"\n"<<"Min: "<<min;

    return 0;
}
