// { Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

 // } Driver Code Ends
class Solution{

	public:
	int minCoins(int coins[], int N, int AMT) 
	{ 
	    // Your code goes here
	    int*dp = new int[AMT + 1];
	    
	    for(int i=0;i<AMT+1;i++) dp[i] = AMT;
	    dp[0] = 0;
	    
	    for(int i=0;i<N;i++){
	        for(int j=coins[i];j<AMT+1;j++){
	            if(dp[j - coins[i]] >= 0) dp[j] = min(dp[j], 1 + dp[j - coins[i]]);
	        }
	    }
	    
	    return dp[AMT] == AMT ? -1 : dp[AMT];
	} 
	  
};

// { Driver Code Starts.
int main() 
{
   
   
   	int t;
    cin >> t;
    while (t--)
    {
        int v, m;
        cin >> v >> m;

        int coins[m];
        for(int i = 0; i < m; i++)
        	cin >> coins[i];

      
	    Solution ob;
	    cout << ob.minCoins(coins, m, v) << "\n";
	     
    }
    return 0;
}
  // } Driver Code Ends