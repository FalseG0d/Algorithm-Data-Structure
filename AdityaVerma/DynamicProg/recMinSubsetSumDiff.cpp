// { Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

 // } Driver Code Ends
class Solution{

  public:
    int mod(int x){
        return x>0?x:-x;
    }
    int help(int arr[],int n,int sum1,int sum2) {
        if(n==0) return mod(sum1-sum2);
        
        return min(help(arr,n-1,sum1,sum2),help(arr,n-1,sum1-arr[n-1],sum2+arr[n-1]));
    }
	int minDifference(int arr[], int n)  { 
	    // Your code goes here
	    int sum=0;
	    
	    for(int i=0;i<n;i++) sum+=arr[i];
	    
	    return help(arr,n,sum,0);
	} 
};


// { Driver Code Starts.
int main() 
{
   
   
   	int t;
    cin >> t;
    while (t--)
    {
        int n;
        cin >> n;

        int a[n];
        for(int i = 0; i < n; i++)
        	cin >> a[i];

       

	    Solution ob;
	    cout << ob.minDifference(a, n) << "\n";
	     
    }
    return 0;
}  // } Driver Code Ends