// { Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

 // } Driver Code Ends


class Solution
{
    public:
    //Function to reverse words in a given string.
    string reverseWords(string S) 
    { 
        // code here 
        
        for(int i=0;S[i]!='\0';i++){
            if(S[i] == '.') S[i] = 32;
        }
        
        // cout<<S<<"\n";
        
        stringstream ss(S);
        string str;
        
        string res = "";
        
        while(ss>>str){
            str += ".";
            res = str + res;
            
            // cout<<str<<"\n";
        }
        
        int n = res.length();
        
        return res.substr(0,n-1);
    } 
};

// { Driver Code Starts.
int main() 
{
    int t;
    cin >> t;
    while (t--) 
    {
        string s;
        cin >> s;
        Solution obj;
        cout<<obj.reverseWords(s)<<endl;
    }
}  // } Driver Code Ends