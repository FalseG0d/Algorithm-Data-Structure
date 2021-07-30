#include <iostream>
using namespace std;

int*dp;

int fib(int n){
    // write your code here
    if(n<0) return 0;
    if(dp[n]!=-1) return dp[n];

    return fib(n-1)+fib(n-2);
}

int main(){
    int n;
    cin>>n;
    
    dp=new int[n+1];
    for(int i=0;i<n+1;i++)dp[i]=-1;
    dp[0]=0;dp[1]=1;
    
    cout<<fib(n)<<endl;
    return 0;
}