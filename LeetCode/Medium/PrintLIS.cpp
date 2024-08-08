//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
class Solution {
  public:
    vector<int> longestIncreasingSubsequence(int n, vector<int>& arr) {
        // Code here
        if(n == 1) return arr;
        
        vector<int>dp(n, 1);
        vector<int>prev(n, -1);
        
        for(int i=1;i<n;i++) {
            for(int j=0;j<i;j++) {
                if(arr[i] > arr[j]) {
                    if(1 + dp[j] > dp[i]) {
                        dp[i] = 1 + dp[j];
                        prev[i] = j;
                    }
                }
                
            }
        }
        
        int maxLen = -1;
        int lstIdx = -1;
        
        for(int i=0;i<n;i++) {
            if(dp[i] > maxLen) {
                maxLen = dp[i];
                lstIdx = i;
            }
        }
        
        vector<int>res;
        while(lstIdx > -1) {
            res.push_back(arr[lstIdx]);
            lstIdx = prev[lstIdx];
        }
        
        reverse(res.begin(), res.end());
        
        return res;
    }
};

//{ Driver Code Starts.

int main() {
    int t;
    cin >> t;
    while (t--) {
        int N;
        cin >> N;
        vector<int> arr(N);
        for (int i = 0; i < N; i++) {
            cin >> arr[i];
        }
        Solution obj;
        vector<int> res = obj.longestIncreasingSubsequence(N, arr);
        for (auto x : res)
            cout << x << " ";
        cout << "\n";
    }
    return 0;
}
// } Driver Code Ends