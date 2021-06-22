// { Driver Code Starts
#include <bits/stdc++.h>
using namespace std;


 // } Driver Code Ends
// User function template for C++

class Solution{
    public:
    // arr[] : int input array of integers
    // k : the quadruple sum required
    vector<vector<int> > fourSum(vector<int> &arr, int target) {
        // Your code goes here
        sort(arr.begin(),arr.end());
        vector<vector<int>>res;
        
        int n=arr.size();
        
        for(int i=0;i<n;i++){
            // if(i>0){
            //     if(arr[i]==arr[i-1])continue;
            // }
            for(int j=i+1;j<n;j++){
                // if(arr[j]==arr[j-1]){
                //     if(j>1)continue;
                // }
                
                int check=target-(arr[i]+arr[j]);
                
                int beg=j+1;
                int end=arr.size()-1;
                
                while(beg<end){
                    int temp=arr[beg]+arr[end];
                    
                    if(temp>check)end--;
                    else if(temp<check)beg++;
                    else {
                        vector<int>itr;
                        
                        itr.push_back(arr[i]);
                        itr.push_back(arr[j]);
                        itr.push_back(arr[beg]);
                        itr.push_back(arr[end]);
                        
                        res.push_back(itr);
                        break;
                    }
                }
                while(j+1<n&&arr[j+1]==arr[j])++j;
            }
            while(i+1<n&&arr[i+1]==arr[i])++i;
        }
        
        return res;
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