//{ Driver Code Starts
// Initial Template for C++

#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
// User function Template for C++

// Back-end complete function Template for C++

class Solution {
  public:
    long long solve(vector<int>& bt) {
        // code here
        long long res = 0;
        long long wait = 0;
        
        int N = bt.size();
        
        sort(bt.begin(), bt.end());
        
        // 1 2 3 4 7
        // 0 1 3 6 10
        
        for(int i=0;i<N;i++) {
            res += wait;
            wait += bt[i];
        }
        
        return res / N;
    }
};

//{ Driver Code Starts.

int main() {
    int t;
    cin >> t;
    while (t--) {
        int n;
        cin >> n;
        vector<int> bt(n), p(n);
        for (int i = 0; i < n; i++) {
            cin >> bt[i];
        }
        Solution obj;
        long long ans = obj.solve(bt);
        cout << ans << "\n";
    }
    return 0;
}
// } Driver Code Ends