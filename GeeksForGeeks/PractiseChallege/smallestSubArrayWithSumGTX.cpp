// { Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

int sb(int arr[], int n, int x);

int main() {
	// your code goes here
	int t;
	cin>>t;
	while(t--)
	{
		int n,x;
		cin>>n>>x;
		int a[n];
		for(int i=0;i<n;i++)
		cin>>a[i];
		
		cout<<sb(a,n,x)<<endl;
	}
	return 0;
}// } Driver Code Ends


int sb(int arr[], int n, int x)
{
    // Your code goes here 
    for(int i=1;i<n;i++){
        arr[i]+=arr[i-1];
    }
    
    int res=INT_MAX;
    
    for(int i=0;i<n;i++){
        if(arr[i]>x){
            res=min(res,i+1);
            for(int j=i-1;j>=0;j--){
                if(arr[i]-arr[j]>x){
                    // cout<<res<<" ";
                    res=min(i-j,res);
                    break;
                }
            }
        }
    }
    
    return res;
}