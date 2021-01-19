// { Driver Code Starts
//Initial template for C++

#include <bits/stdc++.h>
using namespace std;

 // } Driver Code Ends





//User function template for C++

class Solution{   
public:
    static int modulo(int x){
        if(x>0){
            return x;
        }else{
            return -x;
        }
    }
    int getMinDiff(int arr[], int n, int k) {
        sort(arr, arr+n);
        
        int avg=0;
        
        for(int i=0;i<n;i++){
            avg+=arr[i];
        }
        avg/=n;
        
        for(int i=0;i<n;i++){
            if(arr[i]>avg){
                arr[i]=min(modulo(arr[i]-k-avg),modulo(arr[i]-avg));
            }else{
                arr[i]=min(modulo(avg-arr[i]),modulo(avg-arr[i]+k));
            }
        }
        
        sort(arr,arr+n);
        
        return arr[n-1]-arr[0];
    }
};


// { Driver Code Starts.
int main() {
    int t;
    cin >> t;
    while (t--) {
        int n, k;
        cin >> k;
        cin >> n;
        int arr[n];
        for (int i = 0; i < n; i++) {
            cin >> arr[i];
        }
        Solution ob;
        auto ans = ob.getMinDiff(arr, n, k);
        cout << ans << "\n";
    }
    return 0;
}  // } Driver Code Ends