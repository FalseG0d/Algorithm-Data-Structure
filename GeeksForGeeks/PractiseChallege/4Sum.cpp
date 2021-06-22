// { Driver Code Starts
#include <bits/stdc++.h>
using namespace std;


 // } Driver Code Ends
// User function template for C++

class Solution{
    set<vector<int>>res;
    
    public:
    void print(vector<int>itr){
        for(int ele:itr)cout<<ele<<" ";
        cout<<"\n";
    }
    
    void sumOfFour(vector<int>arr,int pos,int target,vector<int>itr){
        // print(itr);
        if(itr.size()==4){
            if(target==0)res.insert(itr);
            return;
        }
        
        if(pos==arr.size()){
            if(target==0&&itr.size()==4)res.insert(itr);
            return;
        }
        
        itr.push_back(arr[pos]);
        target-=arr[pos];
        
        sumOfFour(arr,pos+1,target,itr);
        
        itr.pop_back();
        target+=arr[pos];
        
        sumOfFour(arr,pos+1,target,itr);
    }
    // arr[] : int input array of integers
    // k : the quadruple sum required
    vector<vector<int> > fourSum(vector<int> &arr, int target) {
        // Your code goes here
        int n=arr.size();
        std::sort(arr.begin(),arr.end());
        
        vector<int>itr;
        
        sumOfFour(arr,0,target,itr);
        
        vector<vector<int>>resV;
        
        for(vector<int>v:res){
            resV.push_back(v);
        }
        
        return resV;
    }
};

// { Driver Code Starts.
int main() {
    int t;
    cin >> t;
    while (t--) {
        int n, k, i;
        cin >> n >> k;
        vector<int> a(n);
        for (i = 0; i < n; i++) {
            cin >> a[i];
        }
        Solution ob;
        vector<vector<int> > ans = ob.fourSum(a, k);
        for (auto &v : ans) {
            for (int &u : v) {
                cout << u << " ";
            }
            cout << "$";
        }
        if (ans.empty()) {
            cout << -1;
        }
        cout << "\n";
    }
    return 0;
}  // } Driver Code Ends