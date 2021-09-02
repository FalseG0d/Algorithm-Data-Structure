// { Driver Code Starts
//Initial template for C++

#include <bits/stdc++.h>
using namespace std;

 // } Driver Code Ends
//User function template for C++

class Solution{
  public:
    int longestKSubstr(string s, int K) {
    // your code here
    int N = s.length();
    
    int beg = 0;
    int end = 0;
    
    int map[26];
    memset(map,0,sizeof(map));
    
    int res = -1;
    
    int noDistinctChar = 0;
    
    while(end < N){
        int index = s[end] - 'a';
        
        if(map[index] == 0) noDistinctChar++;
        
        if(noDistinctChar == K) res = max(res,end - beg + 1);
        
        while(noDistinctChar > K){
            map[s[beg] - 'a']--;
            if(map[s[beg] - 'a'] == 0) noDistinctChar--;
            
            beg++;
        }
        
        map[index]++;
        end++;
    }
    
    return res;
    }
};

// { Driver Code Starts.
int main() {
    int t;
    cin >> t;
    while (t--) {
        string s;
        cin >> s;
        int k;
        cin >> k;
        Solution ob;
        cout << ob.longestKSubstr(s, k) << endl;
    }
}
  // } Driver Code Ends