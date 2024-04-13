//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
class Solution{
    int **dp;
  public:
    int help(int arr[], int &n, int itr, int subSetSum, int &sum) {
        if(itr == n) return dp[itr][subSetSum] = abs(sum - 2 * subSetSum);
        
        if(dp[itr][subSetSum] != -1) return dp[itr][subSetSum];
        
        int keep = help(arr, n, itr + 1, subSetSum + arr[itr], sum);
        int skip = help(arr, n, itr + 1, subSetSum, sum);
        
        return dp[itr][subSetSum] = min(keep, skip);
    }
	int minDifference(int arr[], int n)  { 
	    // Your code goes here
	    int sum = 0;
	    dp = new int*[n+1];
	    for(int i=0;i<n;i++) sum += arr[i];
	    
	    for(int i=0;i<=n;i++) dp[i] = new int[sum+1];
	    
	    for(int i=0;i<=n;i++) {
	        for(int j=0;j<=sum;j++) dp[i][j] = -1;
	    }
	    
	   // for(int i=0;i<=n;i++) dp[i][0] = 0;
	   // for(int i=0;i<=sum;i++) dp[0][i] = abs(sum - 2 * i);
	    
	    return help(arr, n, 0, 0, sum);
	    
	   // for(int i=0;i<=n;i++) {
	   //     for(int j=0;j<=sum;j++) cout<<dp[i][j]<<"\t";
	        
	   //     cout<<"\n";
	   // }
	    
	   // return res;
	} 
};


//{ Driver Code Starts.
int main() 
{
   
   
   	int t;
    cin >> t;
    while (t--)
    {
        int n;
        cin >> n;

        int a[n];
        for(int i = 0; i < n; i++)
        	cin >> a[i];

       
    
	    Solution ob;
	    cout << ob.minDifference(a, n) << "\n";
	     
    }
    return 0;
}
// } Driver Code Ends