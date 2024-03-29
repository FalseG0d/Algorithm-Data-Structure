// { Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

 // } Driver Code Ends
class Solution {
  public:
    int toggleBits(int N , int L , int R) {
        // code here
        int range = 0;
        for(int i=L;i<=R;i++){
            range |= 1<<(i-1);
            // cout<<range<<"\n";
        }
        
        // cout<<range<<"\n";
        
        return N ^ range;
    }
};

// { Driver Code Starts.
int main() {
    int t;
    cin >> t;
    while (t--) {
        int N,L,R;
        
        cin>>N>>L>>R;

        Solution ob;
        cout << ob.toggleBits(N,L,R) << endl;
    }
    return 0;
}  // } Driver Code Ends