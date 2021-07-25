#include <iostream>
using namespace std;

int countSubsetWithSum(int arr[],int n,int sum){
    if(n<0||sum<0) return 0;
    
    if(n==0) return sum==0?1:0;
    if(sum==0) return 1;

    return countSubsetWithSum(arr,n-1,sum-arr[n-1])+countSubsetWithSum(arr,n-1,sum);
}

int main() {
    int n;
    cin>>n;
    int x;
    cin>>x;

    int*arr=new int[n];
    for(int i=0;i<n;i++)cin>>arr[i];

    cout<<countSubsetWithSum(arr,n,x);

    return 0;
}
