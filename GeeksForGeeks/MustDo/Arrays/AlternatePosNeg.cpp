// { Driver Code Starts
#include <bits/stdc++.h>

using namespace std;

 // } Driver Code Ends
//User function template for C++
class Solution{
public:

	void rearrange(int arr[], int N) {
	    // code here
	    queue<int>positives;
	    queue<int>negatives;
	    
	    for(int i=0;i<N;i++) if(arr[i] >= 0)positives.push(arr[i]);
	    for(int i=0;i<N;i++) if(arr[i] < 0) negatives.push(arr[i]);
	    
	    int itr = 0;
	    while(!positives.empty() && !negatives.empty()){
	        if(itr%2 == 0){
	            arr[itr] = positives.front();
	            positives.pop();
	        }else{
	            arr[itr] = negatives.front();
	            negatives.pop();
	        }
	        
	        itr++;
	    }
	    while(!positives.empty()){
	        arr[itr] = positives.front();
	        positives.pop();
	        
	        itr++;
	    }
	    while(!negatives.empty()){
	        arr[itr] = negatives.front();
	        negatives.pop();
	        
	        itr++;
	    }
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
        ob.rearrange(arr, n);
        for (i = 0; i < n; i++) {
            cout << arr[i] << " ";
        }
        cout << "\n";
    }
    return 0;
}
  // } Driver Code Ends