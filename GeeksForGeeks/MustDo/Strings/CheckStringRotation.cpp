// { Driver Code Starts
#include <bits/stdc++.h>
using namespace std;


 // } Driver Code Ends
class Solution
{
    public:
    //Function to check if a string can be obtained by rotating
    //another string by exactly 2 places.
    bool isRotated(string str1, string str2)
    {
        // Your code here
        
        int N = str1.length();
        
        if(N < 3) return str1 == str2;
        
        string part1 = str1.substr(2);
        string part2 = str1.substr(0,2);
        
        string part3 = str1.substr(N-2);
        string part4 = str1.substr(0,N-2);
        
        // cout<<part1<<":"<<part2<<":"<<part3<<":"<<part4<<"\n";
        
        return str2 == (part1 + part2) || str2 == (part3 + part4);
        
    }

};


// { Driver Code Starts.

int main() {
	
	int t;
	cin>>t;
	while(t--)
	{
		string s;
		string b;
		cin>>s>>b;
		Solution obj;
		cout<<obj.isRotated(s,b)<<endl;
	}
	return 0;
}
  // } Driver Code Ends