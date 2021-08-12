// { Driver Code Starts
//Initial template for C++

#include<bits/stdc++.h>
using namespace std;


 // } Driver Code Ends
//User function template for C++

class Solution{
  public:
     // Function to find majority element in the array
    // a: input array
    // size: size of input array
    int majorityElement(int A[], int N)
    {
        // your code here
        int ele = INT_MAX;
        int count = 0;
        
        for(int i=0;i<N;i++){
            if(A[i] == ele) count++;
            else if(count == 0) ele = A[i];
            else count--;
        }
        
        count = 0;
        
        for(int i=0;i<N;i++){
            if(A[i] == ele) count++;
        }
        
        if(count > N/2) return ele;
        else return -1;
    }
};

// { Driver Code Starts.

int main(){

    int t;
    cin >> t;

    while(t--){
        int n;
        cin >> n;
        int arr[n];
        
        for(int i = 0;i<n;i++){
            cin >> arr[i];
        }
        Solution obj;
        cout << obj.majorityElement(arr, n) << endl;
    }

    return 0;
}
  // } Driver Code Ends