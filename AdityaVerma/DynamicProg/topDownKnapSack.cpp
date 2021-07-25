// { Driver Code Starts
#include<bits/stdc++.h>
using namespace std;


 // } Driver Code Ends

class Solution
{
    int**dp;
    
    public:
    int help(int W, int wt[], int val[], int n) 
    { 
       // Your code here
       if(n==0||W==0)return 0;
       if(dp[W][n]!=-1)return dp[W][n];
       
       if(wt[n-1]<=W) return dp[W][n]=max(val[n-1]+help(W-wt[n-1],wt,val,n-1),help(W,wt,val,n-1));
       else return dp[W][n]=help(W,wt,val,n-1);
    }
    
    //Function to return max value that can be put in knapsack of capacity W.
    int knapSack(int W, int wt[], int val[], int n) 
    { 
       // Your code here
        dp=new int*[W+1];
        for(int i=0;i<W+1;i++){
            dp[i]=new int[n+1];
        }
        
        for(int i=0;i<W+1;i++)dp[i][0]=0;
        for(int i=0;i<n+1;i++)dp[0][i]=0;
        
        for(int i=1;i<W+1;i++){
            for(int j=1;j<n+1;j++){
                if(wt[j-1]<=i) dp[i][j]=max(val[j-1]+dp[i-wt[j-1]][j-1],dp[i][j-1]);
                else dp[i][j]=dp[i][j-1];
            }
        }
        
        return dp[W][n];
    }
};

// { Driver Code Starts.

int main()
 {
    //taking total testcases
    int t;
    cin>>t;
    while(t--)
    {
        //reading number of elements and weight
        int n, w;
        cin>>n>>w;
        
        int val[n];
        int wt[n];
        
        //inserting the values
        for(int i=0;i<n;i++)
            cin>>val[i];
        
        //inserting the weights
        for(int i=0;i<n;i++)
            cin>>wt[i];
        Solution ob;
        //calling method knapSack()
        cout<<ob.knapSack(w, wt, val, n)<<endl;
        
    }
	return 0;
}  // } Driver Code Ends