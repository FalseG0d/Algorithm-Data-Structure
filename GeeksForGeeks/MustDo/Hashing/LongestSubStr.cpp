// { Driver Code Starts
#include<bits/stdc++.h>
using namespace std;


 // } Driver Code Ends
class Solution{
    public:
    int longestUniqueSubsttr(string S){
        //code
        vector<int>prevOcc(256,-1);
        int N = S.length();
        
        int res = 0;
        int start = 0;
        
        for(int i=0;i<N;i++){
            start = max(start , prevOcc[S[i]] + 1);
            res = max(res , i - start + 1);
            prevOcc[S[i]] = i;
        }
        
        return res;
    }
};

// { Driver Code Starts.
int main()
{
	int t;
	cin>>t;
	while(t--)
	{
		string str;
		cin>>str;
		Solution ob;
		cout<<ob.longestUniqueSubsttr(str)<<endl;
	}
	return 0;
}  // } Driver Code Ends