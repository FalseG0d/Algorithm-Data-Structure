// { Driver Code Starts
#include <bits/stdc++.h>
using namespace std;


 // } Driver Code Ends
//User function template for C++
class Solution{
public:	
    bool check(string s){
        int sum=0;
        
        for(int i=0;s[i]!='\0';i++){
            if(s[i]=='1')sum++;
            else sum--;
        }
        
        return sum>=0;
    }
	vector<string> NBitBinary(int N)
	{
	    // Your code goes here
	    vector<string>res;
	    if(N==1){
	        res.push_back("1");
	        return res;
	    }
	    
	    vector<string> temp=NBitBinary(N-1);
	    
	    for(string s:temp){
	        s+="1";
	        res.push_back(s);
	        s.erase(s.length()-1);
	        s+="0";
	        if(check(s)){
	            res.push_back(s);
	            
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
   		int n;
   		cin >> n;
        Solution ob;
   		vector<string> ans = ob.NBitBinary(n);

   		for(auto i:ans)
   			cout << i << " ";

   		cout << "\n";
   	}

    return 0;
}  // } Driver Code Ends