// { Driver Code Starts
 
#include <bits/stdc++.h>
using namespace std;


 // } Driver Code Ends





//User function template for C++
class Solution{
public:	
	
	int isPlaindrome(string S)
	{
	    // Your code goes here
        stack<char>st;
        
        for(int i=0;S[i]!='\0';i++){
            st.push(S[i]);
        }
        
        int i=0;
        
        while(!st.empty()){
            if(S[i]!=st.top()){
                return 0;
            }
            st.pop();
            i++;
        }
        return 1;
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

   		cout << ob.isPlaindrome(s) << "\n";
   	}

    return 0;
}  // } Driver Code Ends