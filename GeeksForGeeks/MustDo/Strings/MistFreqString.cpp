// { Driver Code Starts
// Initial template for C++

#include <bits/stdc++.h>
using namespace std;

 // } Driver Code Ends
// User function template for C++

class Solution
{
    public:
    //Function to find most frequent word in an array of strings.
    string mostFrequentWord(string arr[], int n) 
    {
        // code here
        map<string,int>mp;
        int maxC = -1;
        
        for(int i=0;i<n;i++){
            mp[arr[i]]++;
            maxC = max(maxC, mp[arr[i]]);
        }
        
        string res;
        
        for(int i=0;i<n;i++){
            if(maxC == mp[arr[i]]){
                res   = arr[i];
                mp[arr[i]]--;
            }
        }
        
        return res;
    }
};

// { Driver Code Starts.
int main() {
    int t;
    cin >> t;
    while (t--) {
        int n;
        cin >> n;

        string arr[n];
        for (int i = 0; i < n; i++) cin >> arr[i];
        Solution obj;
        cout << obj.mostFrequentWord(arr, n) << endl;
    }
    return 0;
}
  // } Driver Code Ends