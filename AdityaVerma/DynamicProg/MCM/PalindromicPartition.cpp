// { Driver Code Starts
// Initial Template for c++

#include <bits/stdc++.h>
using namespace std;

 // } Driver Code Ends
// User function Template for C++

class Solution{
public:
    int**dp;
    bool isPalin(string str,int beg,int end){
        while(beg < end){
            if(str[beg] != str[end]) return false;
            beg++;
            end--;
        }
        
        return true;
    }
    int solve(string str,int beg,int end){
        if(beg == end) return dp[beg][end] = 0;
        
        if(dp[beg][end] != -1) return dp[beg][end];
        if(isPalin(str,beg,end)) return dp[beg][end] = 0;
        
        int res = INT_MAX;
        
        for(int i=beg;i<end;i++){
            int left;
            int right;
            
            if(dp[beg][i] != -1) left = dp[beg][i];
            else dp[beg][i] = left = solve(str,beg,i);
            
            if(dp[i+1][end] != -1) right= dp[i+1][end];
            else dp[i+1][end] = right = solve(str,i+1,end);
            
            int count  = 1 + left + right;
            
            // int count = 1 + solve(str,beg,i) + solve(str,i+1,end);
            
            res = min(res,count);
        }
        
        return dp[beg][end] = res;
    }
    int palindromicPartition(string str)
    {
        // code here
        int N = str.length();
        if(N == 0) return 0;
        
        dp = new int*[N];
        for(int i=0;i<N;i++) dp[i] = new int[N];
        
        for(int i=0;i<N;i++){
            for(int j=0;j<N;j++) dp[i][j] = -1;
        }
        
        return solve(str,0,N-1);
    }
};

// { Driver Code Starts.

int main(){
    int t;
    cin>>t;
    while(t--){
        string str;
        cin>>str;
        
        Solution ob;
        cout<<ob.palindromicPartition(str)<<"\n";
    }
    return 0;
}  // } Driver Code Ends