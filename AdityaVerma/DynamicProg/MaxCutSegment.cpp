// { Driver Code Starts
#include<bits/stdc++.h>
using namespace std;



 // } Driver Code Ends


class Solution
{
    public:
    int*dp;
    //Function to find the maximum number of cuts.
    int max(int x, int y, int z){
        if(x>y){
            if(x>z) return x;
            else return z;
        }else{
            if(y>z) return y;
            else return z;
        }
    }
    int maximizeTheCuts(int n, int x, int y, int z)
    {
        //Your code here
        dp = new int[n+1];
        dp[0] = 0;
        
        for(int i=1;i<=n;i++){
            int x_1 = i - x < 0 ? INT_MIN : dp[i - x];
            int y_1 = i - y < 0 ? INT_MIN : dp[i - y];
            int z_1 = i - z < 0 ? INT_MIN : dp[i - z];
            
            dp[i] = 1 + max(x_1,y_1,z_1);
        }
        
        return dp[n] < 0 ? 0 : dp[n];
        // for(int i=0;i<=n;i++)cout<<dp[i]<<" ";
    }
};

// { Driver Code Starts.
int main() {
    
    //taking testcases
    int t;
    cin >> t;
    while(t--)
    {
        //taking length of line segment
        int n;
        cin >> n;
        
        //taking types of segments
        int x,y,z;
        cin>>x>>y>>z;
        Solution obj;
        //calling function maximizeTheCuts()
        cout<<obj.maximizeTheCuts(n,x,y,z)<<endl;

    }

	return 0;
}  // } Driver Code Ends