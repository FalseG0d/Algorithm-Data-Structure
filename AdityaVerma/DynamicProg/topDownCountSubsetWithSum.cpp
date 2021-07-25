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

    int**dp=new int*[x+1];
    for(int i=0;i<x+1;i++)dp[i]=new int[n+1];

    for(int i=0;i<x+1;i++){
        for(int j=0;j<n+1;j++)dp[i][j]=-1;
    }

    for(int i=0;i<x+1;i++)dp[i][0]=0;
    for(int i=0;i<n+1;i++)dp[0][i]=1;

    for(int i=1;i<x+1;i++){
        for(int j=1;j<n+1;j++){
            if(i-arr[j-1]>=0) dp[i][j]=dp[i-arr[j-1]][j-1]+dp[i][j-1];
            else dp[i][j]=dp[i][j-1];
        }
    }

    cout<<dp[x][n];

    return 0;
}
