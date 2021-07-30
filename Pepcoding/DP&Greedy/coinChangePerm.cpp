#include <bits/stdc++.h>
using namespace std;

int main() {
    int n;
    cin>>n;

    int*arr=new int[n];
    for(int i=0;i<n;i++) cin>>arr[i];

    sort(arr,arr+n);

    int amt;
    cin>>amt;

    int*dp=new int[amt+1];
    for(int i=0;i<amt+1;i++) dp[i]=0;
    dp[0]=1;

    // for(int i=0;i<amt+1;i++) cout<<dp[i]<<" ";

    for(int i=1;i<amt+1;i++){
        for(int j=0;j<n;j++){
            if(i-arr[j]<0) break;

            dp[i]+=dp[i-arr[j]];
        }
    }

    // for(int i=0;i<amt+1;i++) cout<<dp[i]<<" ";

    cout<<dp[amt];

    return 0;
}
