// { Driver Code Starts
// Initial Template for C++

#include <bits/stdc++.h>
using namespace std;

 // } Driver Code Ends
// User function Template for C++

class Solution{
public:
    int dp[201][201][2];
    int solve(string S,int beg,int end,bool req){
        if(beg > end) return dp[beg][end][req] = 0;
        if(beg == end){
            if(req) return dp[beg][end][req] = S[beg] == 'T' ? 1 : 0;
            else return dp[beg][end][req] = S[beg] == 'F' ? 1 : 0;
        }
        
        if(dp[beg][end][req] != -1) return dp[beg][end][req];
        
        int res = 0;
        
        for(int i=beg+1;i<end;i+=2){
            int lT = solve(S,beg,i-1,true);
            int lF = solve(S,beg,i-1,false);
            
            int rT = solve(S,i+1,end,true);
            int rF = solve(S,i+1,end,false);
            
            if(S[i] == '&'){
                if(req) res += (lT * rT);
                else res += ((lT * rF) + (lF * rT) + (lF * rF));
            }else if(S[i] == '|'){
                if(req) res += ((lT * rF) + (lF * rT) + (lT * rT));
                else res += (lF * rF);
            }else if(S[i] == '^'){
                if(req) res += ((lT * rF) + (lF * rT));
                else res += ((lT * rT) + (lF * rF));
            }
        }
        
        return dp[beg][end][req] = res % 1003;
    }
    int countWays(int N, string S){
        // code here
        memset(dp,-1,sizeof(dp));
        
        return solve(S,0,N-1,true);
    }
};

// { Driver Code Starts.

int main(){
    int t;
    cin>>t;
    while(t--){
        int N;
        cin>>N;
        string S;
        cin>>S;
        
        Solution ob;
        cout<<ob.countWays(N, S)<<"\n";
    }
    return 0;
}  // } Driver Code Ends