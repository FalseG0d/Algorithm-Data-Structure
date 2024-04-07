//{ Driver Code Starts
#include<bits/stdc++.h>
using namespace std;

// } Driver Code Ends
class Solution
{
	public:
		void help(string s1, string s2, set<string>&res)
		{
		    int n = s1.length();
		    
		    if(n == 0) {
		        res.insert(s2);
		        return;
		    }
		    if(n == 1) help("", s2 + s1, res);
		    
		    for(int i=0;i<n;i++) {
		        string left = s1.substr(0, i);
		        string right = s1.substr(i+1);
		        
		        help(left + right, s2 + s1[i], res);
		    }
		}
		vector<string>find_permutation(string S)
		{
		    // Code here there
		    set<string>res;
		    
		    help(S, "", res);
		    vector<string>vc(res.begin(), res.end());
		    
		    return vc;
		}
};



//{ Driver Code Starts.
int main(){
    int t;
    cin >> t;
    while(t--)
    {
	    string S;
	    cin >> S;
	    Solution ob;
	    vector<string> ans = ob.find_permutation(S);
	    sort(ans.begin(),ans.end());
	    for(auto i: ans)
	    {
	    	cout<<i<<" ";
	    }
	    cout<<"\n";
    }
	return 0;
}

// } Driver Code Ends