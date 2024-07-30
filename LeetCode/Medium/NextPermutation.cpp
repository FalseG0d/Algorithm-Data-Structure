//{ Driver Code Starts
// Initial Template for C++

#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
// User function Template for C++

class Solution{
public:
    vector<int> nextPermutation(int N, vector<int> arr){
        // code here
        // 1 2 3 4
        // 1 2 4 3
        // 1 3 2 4
        // 1 3 4 2
        // 1 4 2 3
        // 1 4 3 2
        // 2 1 3 4
        
        // Find decreasing slope
        int i=N-1;
        
        for(;i>0;i--) {
            int curr = arr[i];
            int prev = arr[i-1];
            
            int slope = curr - prev;
            
            if(slope > 0) break;
            else continue;
        }
        
        // Position to replace
        int pos = i - 1;
        // Replace with the Next largest number in the vector
        
        sort(arr.begin() + pos + 1, arr.end());
        
        if(pos == -1) return arr;
        
        for(int i=pos+1;i<N;i++) {
            if(arr[i] > arr[pos]) {
                swap(arr[i], arr[pos]);
                break;
            }
        }
        
        return arr;
    }
};

//{ Driver Code Starts.

int main(){
    int t;
    cin>>t;
    while(t--){
        int N;
        cin>>N;
        vector<int> arr(N);
        for(int i = 0;i < N;i++)
            cin>>arr[i];
        
        Solution ob;
        vector<int> ans = ob.nextPermutation(N, arr);
        for(int u: ans)
            cout<<u<<" ";
        cout<<"\n";
    }
    return 0;
}
// } Driver Code Ends