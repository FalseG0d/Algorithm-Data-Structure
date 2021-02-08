// { Driver Code Starts
#include <bits/stdc++.h>

using namespace std;

 // } Driver Code Ends




#define ll long long

//User function template for C++
class Solution{
public:
	// Function to find maximum product subarray
	long long maxProduct(int *arr, int n) {
	    // code here
	    
	    ll res,minP,maxP;
	    res=minP=maxP=1;
	   // cout<<"maxP\tminP\tres\n";
	    for(int i=0;i<n;i++){
	        ll x=arr[i];
	        
	        if(x<0)
	            swap(minP,maxP);
	            
	        maxP=max(x,x*maxP);
	        minP=min(x,x*minP);
	        
	        res=max(maxP,res);
	       // cout<<maxP<<"\t"<<minP<<"\t"<<res<<"\n";
	    }
	    
	    return res;
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
        auto ans = ob.maxProduct(arr, n);
        cout << ans << "\n";
    }
    return 0;
}  // } Driver Code Ends 