// { Driver Code Starts
#include <bits/stdc++.h>

using namespace std;


 // } Driver Code Ends
//User function template for C++
class Solution{
public:	
	int findKRotation(int arr[], int n) {
	    // code here
	    
	    int l=0;
	    int r=n-1;
	    
	    if(arr[l]<arr[r])return 0;
	    
	    int mid;
	    
	    while(l<=r){
	        mid=l+(r-l)/2;
	        
	        int next=(mid+1)%n;
	        int prev=(mid-1+n)%n;
	        
	        if(arr[mid]<arr[next]&&arr[mid]<arr[prev])break;
	        
	        if(arr[mid]<arr[r])r=mid-1;
	        else l=mid+1;
	        
	       // cout<<arr[mid]<<" ";
	    }
	   // cout<<arr[mid]<<"\n";
	    
	    return mid;
	}

};

// { Driver Code Starts.

int main() {
    int t;
    cin >> t;
    while (t--) {
        int n, i;
        cin >> n;
        int a[n];
        for (i = 0; i < n; i++) {
            cin >> a[i];
        }
        Solution ob;
        auto ans = ob.findKRotation(a, n);
        cout << ans << "\n";
    }
    return 0;
}
  // } Driver Code Ends