// { Driver Code Starts
#include<bits/stdc++.h>
using namespace std;

 // } Driver Code Ends
class Solution
{
	public:
	    void help(vector<string>&res,string S,string ans){
	        if(S.length() == 0){
	            res.push_back(ans);
	            return;
	        }
	        
	        int n = S.length();
	        
	        for(int i=0;i<n;i++){
	            string leftSubstr = S.substr(0,i);
	            string rightSubstr = S.substr(i+1);
	            
	            string perm = leftSubstr+rightSubstr;
	            
	            help(res,perm,ans+S[i]);
	        }
	        
	    }
		vector<string>find_permutation(string S)
		{
		    // Code here there
		    vector<string> res;
		    
		    help(res,S,"");
		    
		    sort(res.begin(),res.end());
		    
		    return res;
		}
};



// { Driver Code Starts.
int main(){
    int t;
    cin >> t;
    while(t--)
    {
	    string S;
	    cin >> S;
	    Solution ob;
	    vector<string> ans = ob.find_permutation(S);
	    for(auto i: ans)
	    {
	    	cout<<i<<" ";
	    }
	    cout<<"\n";
    }
	return 0;
}
  // } Driver Code Ends