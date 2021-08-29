#include <iostream>
using namespace std;

int countVal(int arr[],int n,int val){
    int**dp=new int*[val+1];
    for(int i=0;i<val+1;i++)dp[i]=new int[n+1];

    for(int i=0;i<val+1;i++)dp[i][0]=0;
    for(int i=0;i<n+1;i++)dp[0][i]=1;

    for(int i=1;i<val+1;i++){
        for(int j=1;j<n+1;j++){
            if(i>=arr[j-1]) dp[i][j]=dp[i-arr[j-1]][j-1]+dp[i][j-1];
            else dp[i][j]=dp[i][j-1];
        }
    }

    return dp[val][n];
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
