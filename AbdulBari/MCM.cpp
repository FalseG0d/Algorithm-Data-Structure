#include <iostream>
#define INT_MAX 2147483647

using namespace std;

int**dp;

int MCM(int arr[],int i,int j){
    if(i>j) return 0;
    if(i==j) return dp[i-1][j-1]=0;

    int ans=INT_MAX;
    for(int k=i;k<j;k++){
        int temp=MCM(arr,i,k)+MCM(arr,k+1,j)+arr[i-1]*arr[k]*arr[j];

        ans=min(ans,temp);
    }

    return dp[i-1][j-1]=ans;
}

int main() {
    int n;
    cin>>n;
    int*arr=new int[n];
    for(int i=0;i<n;i++) cin>>arr[i];

    dp=new int*[n-1];
    for(int i=0;i<n-1;i++) dp[i]=new int[n-1];

    for(int i=0;i<n-1;i++){
        for(int j=0;j<n-1;j++)dp[i][j]=-1;
    }

    cout<<MCM(arr,1,n-1)<<"\n";
    
    for(int i=0;i<n-1;i++){
        for(int j=0;j<n-1;j++){
            if(dp[i][j]!=-1) cout<<dp[i][j];
            else cout<<" ";
            cout<<"\t";
            }
        cout<<"\n";
    }

    return 0;
}
