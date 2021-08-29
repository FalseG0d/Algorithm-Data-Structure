// { Driver Code Starts
#include<bits/stdc++.h>
const int mod=1e9+7;
using namespace std;

 // } Driver Code Ends
// function to find longest common subsequence

class Solution
{
    public:
    //Function to find the length of longest common subsequence in two strings.
    int**dp;
    
    int help(int x, int y, string s1, string s2)
    {
        if(dp[x][y] != -1) return dp[x][y];
        if(x == 0 || y == 0) return dp[x][y] = 0;
        
        return dp[x][y] = s1[x-1] == s2[y-1] ? 1 + help(x-1,y-1,s1,s2) : max(help(x-1,y,s1,s2), help(x,y-1,s1,s2));
    }
    
    int lcs(int x, int y, string s1, string s2)
    {
        // your code here
        dp = new int*[x+1];
        for(int i=0;i<x+1;i++) dp[i] = new int[y+1];
        
        for(int i=0;i<x+1;i++){
            for(int j=0;j<y+1;j++) dp[i][j] = -1;
        }
        
        return help(x,y,s1,s2);
    }
};


// { Driver Code Starts.
int main()
{
    int t,n,k,x,y;
    cin>>t;
    while(t--)
    {
        cin>>x>>y;          // Take size of both the strings as input
        string s1,s2;
        cin>>s1>>s2;        // Take both the string as input
        Solution ob;
        cout << ob.lcs(x, y, s1, s2) << endl;
    }
    return 0;
}
  // } Driver Code Ends