// { Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

 // } Driver Code Ends
class Solution{
		

	public:
	int minOperations(string str1, string str2) 
	{ 
	    // Your code goes here
	    int X = str1.length();
	    int Y = str2.length();
	    
	    int**dp = new int*[X + 1];
	    for(int i=0;i<X+1;i++) dp[i] = new int[Y + 1];
	    
	    for(int i=0;i<X+1;i++) dp[i][0] = 0;
	    for(int i=0;i<Y+1;i++) dp[0][i] = 0;
	    
	    for(int i=1;i<X+1;i++){
	        for(int j=1;j<Y+1;j++){
	            if(str1[i-1] == str2[j-1]) dp[i][j] = 1 + dp[i-1][j-1];
	            else dp[i][j] = max(dp[i-1][j],dp[i][j-1]);
	        }
	    }
	    
	    return Y + X - 2 * dp[X][Y];
	} 
};

// { Driver Code Starts.
int main() 
{
   	
   
   	int t;
    cin >> t;
    while (t--)
    {
        string s1, s2;
        cin >> s1 >> s2;

	    Solution ob;
	    cout << ob.minOperations(s1, s2) << "\n";
	     
    }
    return 0;
}

  // } Driver Code Ends