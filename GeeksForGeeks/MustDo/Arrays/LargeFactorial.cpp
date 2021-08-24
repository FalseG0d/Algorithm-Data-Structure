// { Driver Code Starts
#include <bits/stdc++.h>
using namespace std;


 // } Driver Code Ends
//User function template for C++


class Solution{
public:
    vector<long long> factorial(vector<long long> a, int N) {
        long long maxVal = -1;
        for(int i=0;i<N;i++) maxVal = max(maxVal, a[i]);
        
        long long*fact = new long long[maxVal + 1];
        
        fact[0] = fact[1] = 1;
        for(int i=2;i<maxVal + 1;i++) fact[i] = (fact[i-1] * i) % 1000000007;
        
        vector<long long>res;
        
        for(int i=0;i<N;i++) res.push_back(fact[a[i]]);
        
        return res;
    }
};

// { Driver Code Starts.

int main() {
    int t;
    cin >> t;
    while (t--) {
        int n, i;
        cin >> n;
        vector<long long> a(n);
        for (i = 0; i < n; i++) {
            cin >> a[i];
        }
        Solution ob;
        vector<long long> res = ob.factorial(a, n);
        for (i = 0; i < n; i++) {
            cout << res[i] << " ";
        }
        cout << "\n";
    }
    return 0;
}
  // } Driver Code Ends