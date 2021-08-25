// { Driver Code Starts
#include <bits/stdc++.h>

using namespace std;


 // } Driver Code Ends
class Solution{
public:
    // m is maximum of number zeroes allowed to flip
    // n is size of array
    int findZeroes(int arr[], int n, int m) {
        // code here
        int res = 0;
        int cnt0= 0;
        
        int left = 0;
        int right= 0;
        
        while(right < n){
            if(arr[right] == 0) cnt0++;
            
            while(cnt0 > m){
                if(arr[left] == 0) cnt0--;
                
                left++;
            }
            
            res = max(res,right - left + 1);
            right++;
        }
        
        return res;
    }  
};

// { Driver Code Starts.

int main() {
    int t;
    cin >> t;
    while (t--) {
        int n, i, m;
        cin >> n;
        int arr[n];
        for (i = 0; i < n; i++) {
            cin >> arr[i];
        }
        cin >> m;
        Solution ob;
        auto ans = ob.findZeroes(arr, n, m);
        cout << ans << "\n";
    }
    return 0;
}  // } Driver Code Ends