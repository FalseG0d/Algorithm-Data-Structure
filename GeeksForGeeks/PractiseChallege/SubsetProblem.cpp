//{ Driver Code Starts
//Initial template for C++

#include<bits/stdc++.h> 
using namespace std; 

// } Driver Code Ends
//User function template for C++

class Solution{
public:
    bool isSubsetSum(vector<int>arr, int sum){
        // code here 
        int N = arr.size();
        
        int**dp = new int*[N+1];
        for(int i=0;i<N+1;i++){
            dp[i] = new int[sum + 1];
        }
        
        for(int i=0;i<sum+1;i++) dp[0][i] = false;
        for(int i=0;i<N+1;i++) dp[i][0] = true;
        
        for(int i=1;i<N+1;i++){
            for(int j=1;j<sum+1;j++){
                if(arr[i-1] <= j){
                    dp[i][j] = dp[i-1][j] || dp[i-1][j - arr[i-1]];
                }else{
                    dp[i][j] = dp[i-1][j];
                }
            }
        }
        
        // for(int i=0;i<N+1;i++){
        //     for(int j=0;j<sum+1;j++) cout<<dp[i][j]<<" ";
        //     cout<<"\n";
        // }
        
        return dp[N][sum];
    }
};

//{ Driver Code Starts.
int main() 
{ 
    int t;
    cin>>t;
    while(t--)
    {
        int N, sum;
        cin >> N;
        vector<int> arr(N);
        for(int i = 0; i < N; i++){
            cin >> arr[i];
        }
        cin >> sum;
        
        Solution ob;
        cout << ob.isSubsetSum(arr, sum) << endl;
    }
    return 0; 
} 

// } Driver Code Ends