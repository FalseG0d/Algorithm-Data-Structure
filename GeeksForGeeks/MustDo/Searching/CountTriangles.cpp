// { Driver Code Starts
#include <bits/stdc++.h>
using namespace std;


 // } Driver Code Ends
class Solution
{
    public:
    //Function to count the number of possible triangles.
    int findNumberOfTriangles(int arr[], int N)
    {
        // code here
        sort(arr,arr+N,greater<int>());
        int res = 0;
        
        for(int i=0;i<N-2;i++){
            int A = arr[i];
            int beg = i + 1;
            int end = N - 1;
            
            while(beg < end){
                int temp = arr[beg] + arr[end];
                
                if(A < temp){
                    res += (end - beg);
                    beg++;
                }
                else end--;;
            }
        }
        
        return res;
    }
};


// { Driver Code Starts.

int main()
{
    int T;
    cin>>T;
    while(T--)
    {
        int n;
        cin>>n;
        int arr[n];
        for(int i=0; i<n; i++)
            cin>>arr[i];
        Solution ob;
        cout<<ob.findNumberOfTriangles(arr,n) <<endl;
    }
    return 0;
}  // } Driver Code Ends