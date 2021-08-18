// { Driver Code Starts
// Program to find minimum number of platforms
// required on a railway station
#include <bits/stdc++.h>
using namespace std;


 // } Driver Code Ends
class Solution{
    public:
    //Function to find the minimum number of platforms required at the
    //railway station such that no train waits.
    int findPlatform(int arr[], int dep[], int n)
    {
    	// Your code here
    	if(n == 0) return 0;
    	
    	int ans = 1;
    	
    	vector<pair<int,int>>sch;
    	
    	for(int i=0;i<n;i++){
    	    sch.push_back(make_pair(arr[i],dep[i]));
    	}
    	
    	sort(sch.begin(),sch.end());
    	
    // 	for(int i=0;i<n;i++){
    // 	    cout<<sch[i].first<<"->"<<sch[i].second<<"\n";
    // 	}
    	
    	priority_queue<int,vector<int>,greater<int>>pq;
    	pq.push(sch[0].second);
    	
    	for(int i=1;i<n;i++){
    	    int time_now = sch[i].first;
    	    
    	    while(!pq.empty() && pq.top() < time_now){
    	        pq.pop();
    	    }
    	    
    	    pq.push(sch[i].second);
    	    int curr = pq.size();
    	    
    	    ans = max(ans, curr);
    	}
    	
    	return ans;
    }
};


// { Driver Code Starts.
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
        int dep[n];
        for(int i=0;i<n;i++)
            cin>>arr[i];
        for(int j=0;j<n;j++){
            cin>>dep[j];
        }
        Solution ob;
        cout <<ob.findPlatform(arr, dep, n)<<endl;
    } 
   return 0;
}  // } Driver Code Ends