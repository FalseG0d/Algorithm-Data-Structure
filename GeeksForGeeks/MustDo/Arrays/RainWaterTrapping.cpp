// { Driver Code Starts
#include<bits/stdc++.h>

using namespace std;


 // } Driver Code Ends

class Solution{

    // Function to find the trapped water between the blocks.
    public:
    int trappingWater(int arr[], int N){
        // Code here
        int*gR = new int[N];
        int*gL = new int[N];
        
        gL[0] = -1;
        for(int i=1;i<N;i++) gL[i] = max(arr[i-1],gL[i-1]);
        
        gR[N-1] = -1;
        for(int i=N-2;i>=0;i--) gR[i] = max(arr[i+1],gR[i+1]);
        
        int res = 0;
        
        for(int i=0;i<N;i++){
            if(gL[i] == -1 || gR[i] == -1) continue;
            
            int waterLevel = min(gR[i],gL[i]);
            res += max(0,waterLevel - arr[i]);
        }
        
        return res;
    }
};

// { Driver Code Starts.

int main(){
    
    int t;
    //testcases
    cin >> t;
    
    while(t--){
        int n;
        
        //size of array
        cin >> n;
        
        int a[n];
        
        //adding elements to the array
        for(int i =0;i<n;i++){
            cin >> a[i];            
        }
        Solution obj;
        //calling trappingWater() function
        cout << obj.trappingWater(a, n) << endl;
        
    }
    
    return 0;
}  // } Driver Code Ends