// { Driver Code Starts
#include <iostream>
using namespace std;


 // } Driver Code Ends
class Solution{
    public:
    // Function to find equilibrium point in the array.
    // a: input array
    // n: size of array
    int equilibriumPoint(long long a[], int n) {
        // Your code here
        int*sumLeft = new int[n];
        int*sumRight= new int[n];
        
        sumLeft = 0;
        sumRight = 0;
        
        for(int i=0;i<n;i++) sumRight += a[i];
        
        int ans = -1;
        
        for(int i=0;i<n;i++){
            if(sumLeft == sumRight - a[i]){
                ans = i + 1;
                break;
            }
            
            sumLeft += a[i];
            sumRight -= a[i];
        }
        
        return ans;
    }

};

// { Driver Code Starts.


int main() {

    long long t;
    
    //taking testcases
    cin >> t;

    while (t--) {
        long long n;
        
        //taking input n
        cin >> n;
        long long a[n];

        //adding elements to the array
        for (long long i = 0; i < n; i++) {
            cin >> a[i];
        }
        
        Solution ob;

        //calling equilibriumPoint() function
        cout << ob.equilibriumPoint(a, n) << endl;
    }
    return 0;
}
  // } Driver Code Ends