// { Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

 // } Driver Code Ends
// User function Template for C++

class Solution {
  public:
    int count(int arr[],int n,int val)
    {
        sort(arr,arr+n);
        int ans=0;
        for(int i=0;i<n-2;i++)
        {
            int j=i+1;
            int k=n-1;
            while(j!=k)
            {
                int sum = arr[i]+arr[j]+arr[k];
                if(sum>val)
                k--;
                else
                {
                    ans += (k-j);
                    j++;
                }
            }
        }
        return ans;
    }
    int countTriplets(int arr[], int n, int L, int R) {
        // code here
        int x = count(arr,n,R);
        int y = count(arr,n,L-1);
        return x-y;
    }
};

// { Driver Code Starts.
int main() {
    int t;
    cin >> t;
    while (t--) {
        int N;
        cin >> N;
        int Arr[N];
        for (int i = 0; i < N; i++) cin >> Arr[i];
        int L, R;
        cin >> L >> R;
        Solution obj;
        cout << obj.countTriplets(Arr, N, L, R) << endl;
    }
    return 0;
}  // } Driver Code Ends