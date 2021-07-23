// { Driver Code Starts
//Initial template for C++

#include <bits/stdc++.h>
using namespace std;

 // } Driver Code Ends
//User function template for C++

class Solution{   
public:
    int mod(int x){
        if(x>0)return x;
        else return -x;
    }
    
    struct Comparator{
        bool operator()(pair<int,int>p1,pair<int,int>p2){
            return p1.second>p2.second;
        }
    };
    
    vector<int> printKClosest(vector<int> arr, int n, int k, int x) {
        // code here
        priority_queue<pair<int,int>,vector<pair<int,int>>,Comparator>pq;
        pair<int,int>pp;
        
        for(int i=0;i<n;i++){
            pp.first=arr[i];
            pp.second=mod(arr[i]-x);
            
            pq.push(pp);
        }
        
        vector<int>res;
        
        while(!pq.empty()){
            if(pq.top().first!=x)res.push_back(pq.top().first);
            pq.pop();
            
            if(res.size()==k)break;
        }
        
        return res;
    }
};

// { Driver Code Starts.

int main() {
    int t;
    cin >> t;
    while (t--) {
        int n, k, x;
        cin >> n;
        vector<int> arr(n);
        for (int i = 0; i < n; i++) {
            cin >> arr[i];
        }
        cin >> k >> x;
        Solution ob;
        auto ans = ob.printKClosest(arr, n, k, x);
        for (auto e : ans) {
            cout << e << " ";
        }
        cout << "\n";
    }
    return 0;
}
  // } Driver Code Ends