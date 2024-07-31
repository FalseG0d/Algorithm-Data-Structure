//{ Driver Code Starts
#include <bits/stdc++.h>

using namespace std;

// } Driver Code Ends
class Solution{
public:
    vector<int> findTwoElement(vector<int> arr, int N) {
        // code here
        int expect_sum = N * (N + 1) / 2;
        int actual_sum = 0;
        
        for(int ele : arr) actual_sum += ele;
        
        vector<int>res;
        
        for(int i=0;i<N;i++) {
            if(arr[i] > 0) {
                arr[arr[i] - 1] = -arr[arr[i] - 1];
            } else {
                arr[-arr[i] - 1] = -arr[-arr[i] - 1];
            }
        }
        
        int b = 0;
        
        for(int i=0;i<N;i++) {
            if(arr[i] > 0) {
                b = i+1;
                res.push_back(i+1);
            }
        }
        
        for(int i=0;i<N;i++) {
            if(arr[i] < 0) arr[i] = -arr[i];
            
            if(arr[i] == b) {
                reverse(res.begin(), res.end());
                break;
            }
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
        vector<int> a(n);
        
        for (int i = 0; i < n; i++) {
            cin >> a[i];
        }
        
        Solution ob;
        auto ans = ob.findTwoElement(a, n);
        cout << ans[0] << " " << ans[1] << "\n";
    }
    return 0;
}
// } Driver Code Ends