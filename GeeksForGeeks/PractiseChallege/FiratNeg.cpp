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
    vector<long long>res;
    
    int beg = 0;
    int end = K;
    
    while(end <= N){
        // cout<<beg<<":"<<end-1<<"\n";
        while(beg < end){
            if(A[beg] < 0){
                res.push_back(A[beg]);
                break;
            }
            
            beg++;
        }
        
        if(beg == end) res.push_back(0);
        if(end - K == beg) beg++;
        
        end++;
        // cout<<end<<"\n";
    }
    
    return res;
 }