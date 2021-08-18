// { Driver Code Starts
#include <bits/stdc++.h>
using namespace std;



 // } Driver Code Ends
//User function template for C++
class Solution{
public:	
	
	int countTriplet(int arr[], int N)
	{
	    // Your code goes here
	    int count = 0;
	    
	    sort(arr,arr + N);
	    
	    for(int i=N-1;i>=2;i--){
	        int j = 0;
	        int k = i - 1;
	        
	        while(j < k){
	            if(arr[i] == arr[j] + arr[k]){
	                count++;
	                
	                j++;
	                k--;
	            }else if(arr[i] > arr[j] + arr[k]) j++;
	            else k--;
	        }
	    }
	    
	    return count;
	}
};

// { Driver Code Starts.


int main() 
{
   	
   	ios_base::sync_with_stdio(0);
    cin.tie(NULL);
    cout.tie(NULL);
   
   	int t;
    cin >> t;
    while (t--)
    {
        int n;
        cin >> n;

        int arr[n];
        for(int i = 0; i < n; i++)
        	cin >> arr[i];

        Solution ob;
        cout << ob.countTriplet(arr, n) << "\n";

    }

    return 0;
}  // } Driver Code Ends