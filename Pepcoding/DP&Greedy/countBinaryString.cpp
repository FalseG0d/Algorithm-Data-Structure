#include <iostream>
using namespace std;

int main() {
    int n;
    cin>>n;

    int**dp=new int*[2];
    for(int i=0;i<2;i++) dp[i]=new int[n+1];
    
    dp[0][0]=dp[1][0]=0;
    dp[0][1]=dp[1][1]=1;

    for(int i=2;i<n+1;i++){
        dp[0][i]=dp[1][i-1];
        dp[1][i]=dp[0][i-1]+dp[1][i-1];
    }

    cout<<dp[0][n]+dp[1][n];

    return 0;
}