#include <iostream>
using namespace std;

int main() {
    int n;
    cin>>n;

    int*arr=new int[n];
    for(int i=0;i<n;i++) cin>>arr[i];

    int amt;
    cin>>amt;

    int**dp=new int*[n+1];
    for(int i=0;i<n+1;i++) dp[i]=new int[amt+1];

    for(int i=0;i<n+1;i++) dp[i][0]=1;
    for(int i=1;i<amt+1;i++) dp[0][i]=0;

    for(int i=1;i<n+1;i++){
        for(int j=1;j<amt+1;j++){
            if(j-arr[i-1]>=0) dp[i][j]=dp[i-1][j]+dp[i][j-arr[i-1]];
            else dp[i][j]=dp[i-1][j];
        }
    }

    cout<<dp[n][amt];

    return 0;
}
