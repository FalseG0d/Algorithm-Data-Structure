// { Driver Code Starts
#include <bits/stdc++.h>

using namespace std;

 // } Driver Code Ends
//User function template for C++
class Solution{
public:
	// Function to check if the
	// Pythagorean triplet exists or not
	bool checkTriplet(int arr[], int n) {
	    // code here
	    sort(arr,arr+n);
	    int maxEle = arr[n-1];
	    
	    bool*mp = new bool[maxEle * maxEle + 1]{false};
	    
	    for(int i=0;i<n;i++) mp[arr[i]*arr[i]]=true;
	    
	    for(int i=n-1;i>0;i--){
	        for(int j=i-1;j>=0;j--){
	            if(mp[arr[i]*arr[i] - arr[j]*arr[j]]) return true;
	        }
	    }
	   
	   //for(int i=0;i<maxEle*maxEle+1;i++) cout<<i<<"\t";
	   //cout<<"\n";
	   //for(int i=0;i<maxEle*maxEle+1;i++) cout<<mp[i]<<"\t";
	   //cout<<"\n";
	    
	   return false;
	}
};

// { Driver Code Starts.

int main() {
    int t;
    cin >> t;
    while (t--) {
        int n, i;
        cin >> n;
        int arr[n];
        for (i = 0; i < n; i++) {
            cin >> arr[i];
        }
        Solution ob;
        auto ans = ob.checkTriplet(arr, n);
        if (ans) {
            cout << "Yes\n";
        } else {
            cout << "No\n";
        }
    }
    return 0;
}
  // } Driver Code Ends