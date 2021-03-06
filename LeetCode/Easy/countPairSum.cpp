// { Driver Code Starts
//Initial template for C++

#include <bits/stdc++.h>
using namespace std;

 // } Driver Code Ends


//User function template for C++

class Solution{   
public:
    int getPairsCount(int arr[], int n, int k) {
        std::map<int, vector<int>> m;
        
        for (int i = 0; i < n; ++i) {
            m[arr[i]].push_back(i);
        }
        
        int pairs = 0;
        
        for (int i = 0; i < n - 1; ++i) {
            int req = k - arr[i];
            if (m.count(req) > 0) {
                vector<int> indicies = m[req];
                for (auto el : indicies) {
                    if (el > i) {
                        pairs++;
                    }
                }
            }
        }
        
        return pairs;
    }
};

// { Driver Code Starts.

int main() {
    int t;
    cin >> t;
    while (t--) {
        int n, k;
        cin >> n >> k;
        int arr[n];
        for (int i = 0; i < n; i++) {
            cin >> arr[i];
        }
        Solution ob;
        auto ans = ob.getPairsCount(arr, n, k);
        cout << ans << "\n";
    }
    
    return 0;
}  // } Driver Code Ends