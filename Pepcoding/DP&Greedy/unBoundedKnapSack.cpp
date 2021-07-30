#include <iostream>
using namespace std;

int max(int a,int b){
    return a>b?a:b;
}

int main() {
    int n;
    cin>>n;

    int*val=new int[n];
    int*wt=new int[n];

    for(int i=0;i<n;i++)cin>>val[i];
    for(int i=0;i<n;i++)cin>>wt[i];

    int cap;
    cin>>cap;

    int**dp=new int*[n+1];
    for(int i=0;i<n+1;i++) dp[i]=new int[cap+1];

    for(int i=0;i<n+1;i++) dp[i][0]=0;
    for(int i=0;i<cap+1;i++) dp[0][i]=0;

    for(int i=1;i<n+1;i++){
        for(int j=1;j<cap+1;j++){
            if(j-wt[i-1]>=0){
                int k=1;
                while(j-k*wt[i-1]>=0){
                    dp[i][j]=max(dp[i-1][j],val[i-1]+dp[i][j-wt[i-1]]);
                    k++;
                    }
                }
            else dp[i][j]=dp[i-1][j];
        }
    }

    // for(int i=0;i<n+1;i++){
    //     for(int j=0;j<cap+1;j++)cout<<dp[i][j]<<"\t";
    //     cout<<"\n";
    // }

    cout<<dp[n][cap];

    return 0;
}
