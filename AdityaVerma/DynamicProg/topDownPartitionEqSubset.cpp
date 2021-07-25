// { Driver Code Starts
// Initial Template for C++

#include <bits/stdc++.h>
using namespace std;

 // } Driver Code Ends
// User function Template for C++

class Solution{
public:
    int equalPartition(int N, int arr[])
    {
        // code here
        long sum=0;
        for(int i=0;i<N;i++)sum+=arr[i];
        
        if(sum%2==0){
            sum/=2;
            
            int**dp=new int*[sum+1];
            for(int i=0;i<sum+1;i++)dp[i]=new int[N+1];
            
            for(int i=0;i<sum+1;i++){
                for(int j=0;j<N+1;j++)dp[i][j]=-1;
            }
            
            for(int i=0;i<sum+1;i++)dp[i][0]=0;
            for(int i=0;i<N+1;i++)dp[0][i]=1;
            
            for(int i=1;i<sum+1;i++){
                for(int j=1;j<N+1;j++){
                    if(i-arr[j-1]>=0) dp[i][j]=max(dp[i-arr[j-1]][j-1],dp[i][j-1]);
                    else dp[i][j]=max(0,dp[i][j-1]);
                }
            }
            
            return dp[sum][N];
        }
        else return 0;
    }
};

// { Driver Code Starts.

int main(){
    int t;
    cin>>t;
    while(t--){
        int N;
        cin>>N;
        int arr[N];
        for(int i = 0;i < N;i++)
            cin>>arr[i];
        
        Solution ob;
        if(ob.equalPartition(N, arr))
            cout<<"YES\n";
        else
            cout<<"NO\n";
    }
    return 0;
}  // } Driver Code Ends