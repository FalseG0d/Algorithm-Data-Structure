//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
class Solution {
    int**dp;
  public:
    int help(vector<vector<int>>& arr, int day, int prev) {
        if(day == arr.size()) return 0;
        
        if(dp[day][prev] != -1) return dp[day][prev];
        
        int res = 0;
        
        for(int i=0;i<3;i++) {
            if(i == prev) continue;
            
            res = max(res, arr[day][i] + help(arr, day + 1, i));
        }
        
        // cout<<day<<" "<<prev<<" "<<res<<"\n";
        
        return dp[day][prev] = res;
    }
    int maximumPoints(vector<vector<int>>& arr, int n) {
        // Code here
        int res = 0;
        dp = new int*[n];
        
        for(int i=0;i<n;i++) dp[i] = new int[3];
        
        for(int i=0;i<n;i++) {
            for(int j=0;j<3;j++) dp[i][j] = -1;
        }
        
        for(int i=0;i<3;i++) {
            res = max(res, arr[0][i] + help(arr, 1, i));
        }
        
        return res;
    }
};

//{ Driver Code Starts.
int main() {
    int t;
    cin >> t;
    while (t--) {
        int n;
        cin >> n;
        vector<vector<int>> arr;
        for (int i = 0; i < n; ++i) {
            vector<int> temp;
            for (int j = 0; j < 3; ++j) {
                int x;
                cin >> x;
                temp.push_back(x);
            }
            arr.push_back(temp);
        }

        Solution obj;
        cout << obj.maximumPoints(arr, n) << endl;
    }
    return 0;
}
// } Driver Code Ends