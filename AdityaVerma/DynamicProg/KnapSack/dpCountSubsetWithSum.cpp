#include <iostream>
using namespace std;

int**dp;

int countSubsetWithSum(int arr[],int n,int sum){
    if(n<0||sum<0) return 0;
    if(dp[sum][n]!=-1)return dp[sum][n];
    
    if(n==0) return dp[sum][n]=sum==0?1:0;
    if(sum==0) return dp[sum][n]=1;

    return dp[sum][n]=countSubsetWithSum(arr,n-1,sum-arr[n-1])+countSubsetWithSum(arr,n-1,sum);
}

int main() {
    int n;
    cin>>n;
    int x;
    cin>>x;

    int*arr=new int[n];
    for(int i=0;i<n;i++)cin>>arr[i];

    dp=new int*[x+1];
    for(int i=0;i<x+1;i++)dp[i]=new int[n+1];

    for(int i=0;i<x+1;i++){
        for(int j=0;j<n+1;j++)dp[i][j]=-1;
    }

    cout<<countSubsetWithSum(arr,n,x);

    return 0;
}
