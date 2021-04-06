#include <iostream>
using namespace std;

int*dp;
int cs(int arr[], int n,int pos){
    // write your code here
    if(n-pos<0)return 0;
    // if(n==pos)return 1;
    
    if(dp[pos]!=-1)return dp[pos];
    int res=0;
    
    for(int i=1;i<=arr[pos];i++)res+=cs(arr,n,pos+i);
    dp[pos]=res;
    return res;
}

int main(){
    int n;
    cin>>n;
    int arr[n];
    
    dp=new int[n+1];
    for(int i=0;i<n+1;i++)dp[i]=-1;
    dp[n]=1;
    
    for(int i = 0 ; i < n ;i++){
        cin>>arr[i];
    }
    cout<<cs(arr,n,0)<<endl;
}