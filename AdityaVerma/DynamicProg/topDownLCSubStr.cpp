// { Driver Code Starts
#include<bits/stdc++.h>
using namespace std;

 // } Driver Code Ends
class Solution{
    public:
    
    int longestCommonSubstr (string S1, string S2, int n, int m)
    {
        // your code here
        int**dp = new int*[n+1];
        for(int i=0;i<n+1;i++) dp[i] = new int[m+1];
        
        int result = 0;
        
        for(int i=0;i<n+1;i++){
            for(int j=0;j<m+1;j++){
                if(i == 0 || j == 0){
                    dp[i][j] = 0;
                    continue;
                }
                
                if(S1[i - 1] == S2[j - 1]){
                    dp[i][j] = 1 + dp[i - 1][j - 1];
                    result = max(dp[i][j], result);
                }
                else dp[i][j] = 0;
            }
        }
        
        return result;
    }
};

// { Driver Code Starts.

int main()
{
    int t; cin >> t;
    while (t--)
    {
        int n, m; cin >> n >> m;
        string s1, s2;
        cin >> s1 >> s2;
        Solution ob;

        cout << ob.longestCommonSubstr (s1, s2, n, m) << endl;
    }
}
// Contributed By: Pranay Bansal
  // } Driver Code Ends