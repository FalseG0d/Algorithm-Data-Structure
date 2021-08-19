// { Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

 // } Driver Code Ends
class Solution{
    public:
    long long findMinDiff(vector<long long> a, long long n, long long m){
    //code
    sort(a.begin(),a.end());
    
    // for(int i=0;i<n;i++) cout<<i<<"\t";
    // cout<<"\n";
    // for(int i=0;i<n;i++) cout<<a[i]<<"\t";
    // cout<<"\n";
    
    int res = INT_MAX;
    
    for(int i=0;i<=n-m;i++){
        int check = a[i+m-1] - a[i];
        res = res < check ? res : check;
    }
    
    return res;
    }   
};

// { Driver Code Starts.
int main() {
	long long t;
	cin>>t;
	while(t--)
	{
		long long n;
		cin>>n;
		vector<long long> a;
		long long x;
		for(long long i=0;i<n;i++)
		{
			cin>>x;
			a.push_back(x);
		}
		
		long long m;
		cin>>m;
		Solution ob;
		cout<<ob.findMinDiff(a,n,m)<<endl;
	}
	return 0;
}  // } Driver Code Ends