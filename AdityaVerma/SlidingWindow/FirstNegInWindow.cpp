// { Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

vector<long long> printFirstNegativeInteger(long long int arr[],
                                             long long int n, long long int k);

// Driver program to test above functions
int main() {
    long long int t, i;
    cin >> t;
    while (t--) {
        long long int n;
        cin >> n;
        long long int arr[n];
        for (i = 0; i < n; i++) {
            cin >> arr[i];
        }
        long long int k;
        cin >> k;

        vector<long long> ans = printFirstNegativeInteger(arr, n, k);
        for (auto it : ans) cout << it << " ";
        cout << endl;
    }
    return 0;
}
// } Driver Code Ends




vector<long long> printFirstNegativeInteger(long long int A[],
                                             long long int N, long long int K) {
        long long int left = 0;
        long long int right= 0;
        
        queue<long long int> que;
        
        vector<long long>res;
        
        while(right < N){
            if(A[right] < 0) que.push(right);
            
            if(right - left == K - 1){
                left++;
                
                if(que.empty()) res.push_back(0);
                else{
                    long long int temp = que.front();
                    res.push_back(A[temp]);
                    
                    if(temp < left) que.pop();
                }
                
            }
            
            right++;
        }
        
        return res;
 }