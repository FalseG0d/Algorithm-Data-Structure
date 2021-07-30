#include <bits/stdc++.h>
using namespace std;

int**dp;

int targetSum(int arr[],int n,int target){
    if(target<0) return 0;
    if(n==0) return dp[n][target]=target==0;

    if(dp[n][target]!=-1) return dp[n][target];
    
    return dp[n][target]=max(targetSum(arr,n-1,target-arr[n-1]),targetSum(arr,n-1,target));
}

int main() {
    int n;
    cin>>n;

    int*arr=new int[n];
    for(int i=0;i<n;i++) cin>>arr[i];

    int target;
    cin>>target;

    dp=new int*[n+1];
    for(int i=0;i<n+1;i++) dp[i]=new int[target+1];

    for(int i=0;i<n+1;i++){
        for(int j=0;j<target+1;j++) dp[i][j]=-1;
    }

    // if(targetSum(arr,n,target)>0) cout<<"true";
    // else cout<<"false";

    // cout<<targetSum(arr,n,target)<<"\n";

    targetSum(arr,n,target)?cout<<"true":cout<<"false";

    // for(int i=0;i<n+1;i++){
    //     for(int j=0;j<target+1;j++) cout<<dp[i][j]<<" ";
    //     cout<<"\n";
    // }

    return 0;
}
