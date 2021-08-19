// { Driver Code Starts
#include <bits/stdc++.h>
using namespace std;


 // } Driver Code Ends
//User function template for C++
class Solution{
public:	
		
	string removeDups(string S) 
	{
	    // Your code goes here
	    map<char,int>mp;
	    int N = S.length();
	    
	    string res = "";
	    
	    for(int i=0;i<N;i++){
	        if(mp[S[i]] > 0) continue;
	        else{
	            res += S[i];
	            mp[S[i]]++;
	        }
	    }
	    
	    return res;
	}
};

// { Driver Code Starts.


int main() 
{
   	

   	ios_base::sync_with_stdio(0);
    cin.tie(NULL);
    cout.tie(NULL);
   
   	int t;
   	cin >> t;
   	while(t--)
   	{
   		string s;
   		cin >> s;

   		
   		Solution ob;
   		cout << ob.removeDups(s) << "\n";
   		
   	}

    return 0;
}  // } Driver Code Ends