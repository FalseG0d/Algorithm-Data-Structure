// { Driver Code Starts
#include <bits/stdc++.h>
using namespace std;


 // } Driver Code Ends
class Solution
{
    public:
    //Function to find a continuous sub-array which adds up to a given number.
    vector<int> subarraySum(int arr[], int N, int s)
    {
        // Your code here
        int beg=-1;
        int end=-1;
        
        while(beg < N && end < N){
            if(s == 0) break;
            else if(s > 0) s -= arr[++end];
            else s += arr[++beg];
            
            // cout<<s<<"\n";
        }
        
        vector<int>res;
        
        if(s != 0) res.push_back(-1);
        else{
            res.push_back(beg + 2);
            res.push_back(end + 1);
        }
        
        return res;
    }
};

// { Driver Code Starts.

int main()
 {
    int t;
    cin>>t;
    while(t--)
    {
        int n;
        long long s;
        cin>>n>>s;
        int arr[n];
        
        for(int i=0;i<n;i++)
            cin>>arr[i];
        Solution ob;
        vector<int>res;
        res = ob.subarraySum(arr, n, s);
        
        for(int i = 0;i<res.size();i++)
            cout<<res[i]<<" ";
        cout<<endl;
        
    }
	return 0;
}  // } Driver Code Ends