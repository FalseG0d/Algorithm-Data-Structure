// { Driver Code Starts
//Initial Template for C++


#include <bits/stdc++.h>
using namespace std;

 // } Driver Code Ends
//User function Template for C++

typedef pair<int,int> pi;

class Solution
{
  public:
    vector<int> kTop(int a[], int n, int k) 
    { 
        //code here.
        priority_queue<pi,vector<pi>,greater<pi>>pq;
        unordered_map<int,int>mp;
        
        for(int i=0;i<n;i++)mp[a[i]]++;
        
        pi pp;
        for(auto itr:mp){
            // pp.first=itr.second;
            // pp.second=itr.first;
            
            pq.push({itr.second,itr.first});
            if(pq.size()>k) pq.pop();
        }
        
        vector<int>res;
        while(!pq.empty()){
            res.push_back(pq.top().second);
            pq.pop();
        }
        
        return res;
    }
};


// { Driver Code Starts.

int main() {
	long long t;
	
	cin >> t;
	
	while(t--){
	    long long n;
	    long long k;
	    cin >> n;
	    cin >> k;
	    int a[n];
	    for(long long i = 0;i<n;i++){
	        cin >> a[i];
	    }
	        Solution ob;
	        vector<int> ans;
	        ans=ob.kTop(a,n,k);
	        for(int i=0;i<ans.size();i++)
	        {
	        cout<<ans[i];
	        cout<<" ";
	        }
	        cout<<'\n';
	    }
	return 0;
}
  // } Driver Code Ends