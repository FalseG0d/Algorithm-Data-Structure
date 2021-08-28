// { Driver Code Starts
#include <bits/stdc++.h>
using namespace std;


 // } Driver Code Ends
//User function template for C++

class Solution{
  public:
    int minimumNumberOfDeletions(string S) { 
        // code here
        int N = S.length();
        int**dp = new int*[N+1];
        for(int i=0;i<N+1;i++) dp[i] = new int[N+1];
        
        for(int i=0;i<N+1;i++) dp[i][0] = dp[0][i] = 0;
        
        for(int i=1;i<N+1;i++){
            for(int j=1;j<N+1;j++){
                if(S[i-1] == S[N - j]) dp[i][j] = 1 + dp[i-1][j-1];
                else dp[i][j] = max(dp[i-1][j],dp[i][j-1]);
            }
        }
        
        return S.length() - dp[N][N];
    } 
};

// { Driver Code Starts.
int main(){
    int t;
    cin >> t;
    while(t--){
        string S;
        cin >> S;
        Solution obj;
        cout << obj.minimumNumberOfDeletions(S) << endl;
    }
    return 0;
}  // } Driver Code Ends