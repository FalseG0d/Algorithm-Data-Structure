#include<iostream>
using namespace std;

int n,m;
int**arr;

const int INT_MAX=2147483647;

int min(int a,int b){
    return a<b?a:b;
}

int main(){
    cin>>n>>m;
    
    arr=new int*[n];
    for(int i=0;i<n;i++) arr[i]=new int[m];
    
    for(int i=0;i<n;i++){
        for(int j=0;j<m;j++) cin>>arr[i][j];
    }
    
    int**dp=new int*[n+1];
    for(int i=0;i<n+1;i++)dp[i]=new int[m+1];
    
    for(int i=0;i<n+1;i++)dp[i][0]=INT_MAX;
    for(int i=0;i<m+1;i++)dp[0][i]=INT_MAX;
    
    dp[0][1]=dp[1][0]=0;
    
    for(int i=1;i<n+1;i++){
        for(int j=1;j<m+1;j++) dp[i][j]=arr[i-1][j-1]+min(dp[i-1][j],dp[i][j-1]);
    }
    
    
    // for(int i=0;i<n+1;i++){
    //     for(int j=0;j<m+1;j++) cout<<dp[i][j]<<" ";
    //     cout<<"\n";
    // }
    
    cout<<dp[n][m];
    
    return 0;
}