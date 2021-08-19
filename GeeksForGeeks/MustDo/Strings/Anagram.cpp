// { Driver Code Starts
#include <bits/stdc++.h>
using namespace std;


 // } Driver Code Ends


class Solution
{
    public:
    //Function is to check whether two strings are anagram of each other or not.
    bool isAnagram(string a, string b){
        // Your code here
        int n1 = a.length();
        int n2 = b.length();
        
        if(n1 != n2) return false;
        
        map<char,int>mp;
        
        for(int i=0;a[i]!='\0';i++) mp[a[i]]++;
        
        for(int i=0;b[i]!='\0';i++){
            if(mp[b[i]] == 0) return false;
            else mp[b[i]]--;
        }
        
        return true;
        
    }

};

// { Driver Code Starts.

int main() {
    
    int t;

    cin >> t;

    while(t--){
        string c, d;

        cin >> c >> d;
        Solution obj;
        if(obj.isAnagram(c, d)) cout << "YES" << endl;
        else cout << "NO" << endl;
    }

}
  // } Driver Code Ends