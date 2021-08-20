// { Driver Code Starts
//Initial template for C++

#include <bits/stdc++.h>
using namespace std;

 // } Driver Code Ends
//User function template for C++

class Solution{
  public:
    /*You are required to complete this method */
    int charValue(char ch){
        switch(ch){
            case '0' : return 0;
            case '1' : return 1;
            case '2' : return 2;
            case '3' : return 3;
            case '4' : return 4;
            case '5' : return 5;
            case '6' : return 6;
            case '7' : return 7;
            case '8' : return 8;
            case '9' : return 9;
        }
        
        return -1;
    }
    int atoi(string str) {
        //Your code here
        
        int N = str.length();
        int res=0;
        
        int i = 0;
        bool neg = false;
        if(str[0] == '-'){
            neg = true;
            i=1;
        }
        
        for(;i<N;i++){
            int curr = charValue(str[i]);
            
            if(curr == -1) return -1;
            
            res = res * 10 + curr;
        }
        
        return neg ? -res:res;
    }
};

// { Driver Code Starts.
int main()
{
	int t;
	cin>>t;
	while(t--)
	{
		string s;
		cin>>s;
		Solution ob;
		cout<<ob.atoi(s)<<endl;
	}
}  // } Driver Code Ends