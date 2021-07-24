// { Driver Code Starts
#include<bits/stdc++.h>
using namespace std;


 // } Driver Code Ends

class Solution
{
    int**dp;
    
    public:
    //Function to return max value that can be put in knapsack of capacity W.
    int help(int W, int wt[], int val[], int n) 
    { 
       // Your code here
       if(n==0||W==0)return 0;
       if(dp[W][n]!=-1)return dp[W][n];
       
       if(wt[n-1]<=W) return dp[W][n]=max(val[n-1]+help(W-wt[n-1],wt,val,n-1),help(W,wt,val,n-1));
       else return dp[W][n]=help(W,wt,val,n-1);
    }
    
    int knapSack(int W, int wt[], int val[], int n) 
    { 
       // Your code here
        dp=new int*[W+1];
        for(int i=0;i<W+1;i++){
            dp[i]=new int[n+1];
        }
        
        for(int i=0;i<W+1;i++){
            for(int j=0;j<n+1;j++)dp[i][j]=-1;
        }
        
        int res=help(W,wt,val,n);
        
        // for(int i=0;i<W+1;i++){
        //     for(int j=0;j<n+1;j++)cout<<dp[i][j]<<" ";
        //     cout<<"\n";
        // }
        
        return res;
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