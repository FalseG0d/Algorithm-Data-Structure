// { Driver Code Starts
#include<bits/stdc++.h>
using namespace std;

 // } Driver Code Ends
class Solution
{
  public:
    long long int count(int S[], int N, int amt)
    {
        long long int dp[amt + 1]{0};
        dp[0] = 1;
        
        // for(int i=0;i<amt+1;i++) cout<<dp[i]<<" ";
        // cout<<"\n";
        
        for(int i=0;i<N;i++){
            for(int j=S[i];j<=amt;j++){
                dp[j] += dp[j - S[i]];
            }
        }
        
        // for(int i=0;i<amt+1;i++) cout<<dp[i]<<" ";
        // cout<<"\n";
        
        return dp[amt];
    }
};

// { Driver Code Starts.
int main()
{
    int t;
    cin>>t;
	while(t--)
	{
		int n,m;
		cin>>n>>m;
		int arr[m];
		for(int i=0;i<m;i++)
		    cin>>arr[i];
	    Solution ob;
		cout<<ob.count(arr,m,n)<<endl;
	}
    
    
    return 0;
}  // } Driver Code Ends