#include <iostream>
using namespace std;

int countVal(int arr[],int n,int val){
    if(n==0) return val==0?1:0;
    if(val<0) return 0;

    return countVal(arr,n-1,val-arr[n-1])+countVal(arr,n-1,val);
}

int countSubsetDiff(int arr[],int n,int diff){
    int sum=0;

    for(int i=0;i<n;i++)sum+=arr[i];
    sum-=diff;

    if(sum%2==0)return countVal(arr,n,sum/2);
    else return 0;
}

int main() {
    int n;
    cin>>n;

    int*arr=new int[n];
    for(int i=0;i<n;i++)cin>>arr[i];

    int diff;
    cin>>diff;

    cout<<countSubsetDiff(arr,n,diff);

    return 0;
}
