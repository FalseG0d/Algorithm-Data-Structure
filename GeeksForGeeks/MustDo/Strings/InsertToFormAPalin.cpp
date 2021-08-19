// { Driver Code Starts
//Initial template for C++

#include <bits/stdc++.h>
using namespace std;

 // } Driver Code Ends
//User function template for C++

class Solution{
  public:
    int LCS(string str1,string str2){
        int N = str1.length();
        
        int**dp=new int*[N+1];
        for(int i=0;i<N+1;i++) dp[i] = new int[N+1]{0};
        
        for(int i=0;i<N+1;i++){
            for(int j=0;j<N+1;j++){
                if(i == 0 || j == 0) dp[i][j] = 0;
                else if(str1[i-1] == str2[j-1]) dp[i][j] = 1 + dp[i-1][j-1];
                else dp[i][j] = max(dp[i][j-1],dp[i-1][j]);
            }
        }
        
        return dp[N][N];
    }
    int countMin(string str){
    //complete the function here
    string rev = str;
    reverse(rev.begin(),rev.end());
    
    int N = str.length();
    
    int lcs = LCS(str,rev);
    
    return N - lcs;
    }
};

// { Driver Code Starts.
int main(){
    int t;
    cin >> t;
    while(t--){
        string str;
        cin >> str;
        Solution ob;
        cout << ob.countMin(str) << endl;
    }
return 0;
}

  // } Driver Code Ends