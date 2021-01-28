// { Driver Code Starts
// A C++ program to find if there is a zero sum
// subarray
#include <bits/stdc++.h>
using namespace std;


bool subArrayExists(int arr[], int n);
// Driver code
int main()
{
	int t;
	cin>>t;
	while(t--)
	{
	    int n;
	    cin>>n;
	    int arr[n];
	    for(int i=0;i<n;i++)
	    cin>>arr[i];
	    	if (subArrayExists(arr, n))
		cout << "Yes\n";
	else
		cout << "No\n";
	}
	return 0;
}// } Driver Code Ends


//Complete this function
bool subArrayExists(int arr[], int n)
{
    //Your code here
    set<int>s;
    
    int sum=0;
    
    for(int i=0;i<n;i++){
        int a=arr[i];
        sum+=a;
        
        if(s.find(sum)!=s.end()||a==0||sum==0){
            return true;
        }
        
        s.insert(sum);
    }
    
    return false;
}


