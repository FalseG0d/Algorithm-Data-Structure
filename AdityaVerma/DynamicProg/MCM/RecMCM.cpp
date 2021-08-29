// { Driver Code Starts
// Initial Template for C++

#include <bits/stdc++.h>
using namespace std;

 // } Driver Code Ends
// User function Template for C++

class Solution{
public:
    int solve(int arr[],int beg,int end){
        if(beg == end) return 0;
        
        int res = INT_MAX;
        
        for(int i=beg;i<end;i++){
            int temp = arr[beg - 1] * arr[i] * arr[end] + solve(arr,beg,i) + solve(arr,i+1,end);
            
            res = min(res,temp);
        }
        
        return res;
    }
    int matrixMultiplication(int N, int arr[])
    {
        // code here
        return solve(arr,1,N-1);
    }
};

// { Driver Code Starts.

int main(){
    int t;
    cin>>t;
    while(t--){
        int N;
        cin>>N;
        int arr[N];
        for(int i = 0;i < N;i++)
            cin>>arr[i];
        
        Solution ob;
        cout<<ob.matrixMultiplication(N, arr)<<endl;
    }
    return 0;
}  // } Driver Code Ends