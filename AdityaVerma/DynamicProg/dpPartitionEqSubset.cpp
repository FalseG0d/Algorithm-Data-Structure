// { Driver Code Starts
// Initial Template for C++

#include <bits/stdc++.h>
using namespace std;

 // } Driver Code Ends
// User function Template for C++

class Solution{
public:
    int**dp;
    int help(int N,int arr[],long sum){
        // if(sum==0)return N>=0;
        // if(N==0)return 0;
        
        // return max(help(N-1,arr,sum-arr[N-1]),help(N-1,arr,sum));
        if(sum<0||N<0) return 0;
        if(dp[sum][N]!=-1) return dp[sum][N];
        
        if(sum==0) return dp[sum][N]=1;
        
        return dp[sum][N]=max(help(N-1,arr,sum-arr[N-1]),help(N-1,arr,sum));
    }
    int equalPartition(int N, int arr[])
    {
        // code here
        long sum=0;
        for(int i=0;i<N;i++)sum+=arr[i];
        
        if(sum%2==0){
            sum/=2;
            dp=new int*[sum+1];
            for(int i=0;i<sum+1;i++)dp[i]=new int[N+1];
            
            for(int i=0;i<sum+1;i++){
                for(int j=0;j<N+1;j++)dp[i][j]=-1;
            }
            
            return help(N,arr,sum/2);
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