// { Driver Code Starts
// Initial Template for C++

#include <bits/stdc++.h>
using namespace std;

 // } Driver Code Ends
//User function template for C++

class Solution{
public:
    string remove(string S){
        // code here
        int N = S.length();
        string res="";
        
        for(int i=0;i<N-1;i++){
            int j;
            char ch = S[i];
            
            for(j=i+1;j<N;j++){
                if(ch != S[j]) break;
                else S[i] = S[j] = ' ';
            }
            
            i=j-1;
        }

        bool flag = false;

        for(int i=0;i<N;i++){
            if(S[i] == ' ') {
                flag = true;
                break;
                }
        }

        if(!flag) return S;
        
        stringstream ss(S);
        string str;
        
        while(ss>>str) res+=str;
        
        return remove(res);
    }
};

// { Driver Code Starts.

int main() {
    int t;
    string tc;
    getline(cin, tc);
    t = stoi(tc);
    while (t--) {
        string s;
        getline(cin, s);
        Solution ob;
        cout << ob.remove(s) << "\n";
    }
    return 0;
}  // } Driver Code Ends