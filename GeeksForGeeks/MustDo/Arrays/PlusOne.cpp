// { Driver Code Starts
#include <bits/stdc++.h>
using namespace std;


 // } Driver Code Ends
//User function Template for C++

class Solution {
  public:
    vector<int> increment(vector<int> arr ,int N) {
        // code here
        vector<int>rev;
        
        int sum=arr[N-1]+1;
        int carry=sum/10;
        sum%=10;
        
        rev.push_back(sum);
        
        for(int i=N-2;i>=0;i--){
            sum=arr[i]+carry;
            carry=sum/10;
            sum%=10;
            
            rev.push_back(sum);
        }
        
        if(carry>0)rev.push_back(carry);
        
        reverse(rev.begin(),rev.end());
        
        return rev;
    }
};

// { Driver Code Starts.

int main() {
    int t;
    cin >> t;
    while (t--) {
        int N;
        char c;
        
        cin>>N;
        vector<int> arr(N);
        
        for(int i=0 ; i<N ; i++)
            cin>>arr[i];

        Solution ob;
        vector<int> res = ob.increment(arr,N);
        for(int i: res)
            cout<<i<<" ";
        cout<<endl;
    }
    return 0;
}  // } Driver Code Ends