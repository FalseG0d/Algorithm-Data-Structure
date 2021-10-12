// { Driver Code Starts
#include <bits/stdc++.h>

using namespace std;


 // } Driver Code Ends
//User function template for C++
class Solution{
public:
    int isAna(string pat, string txt){
        int*arr = new int[256]{0};
        
        for(char ch:pat) arr[ch]++;
        for(char ch:txt) arr[ch]--;
        
        for(int i=0;i<256;i++){
            if(arr[i] != 0) return 0;
        }
        
        return 1;
    }
	int search(string pat, string txt) {
	    // code here
	    int K = pat.length();
	    int N = txt.length();
	    
	    int beg = 0;
	    int end = 0;
	    
	    int check = 0;
	    int hash = 0;
	    
	    int res = 0;
	    
	    for(char ch:pat) hash += ch;
	    
	   // cout<<hash<<" : ";
	    
	    while(end < N){
	        while(end - beg < K) check += txt[end++];
	        
	       // cout<<hash<<" : "<<check<<" : "<<txt.substr(beg, K)<<"\n";
	        if(hash == check) res += isAna(pat, txt.substr(beg, K));
	        
	        check -= txt[beg];
	        
	        beg++;
	    }
	    
	    return res;
	}

};

// { Driver Code Starts.

int main() {
    int t;
    cin >> t;
    while (t--) {
        string pat, txt;
        cin >> txt >> pat;
        Solution ob;
        auto ans = ob.search(pat, txt);
        cout << ans << "\n";
    }
    return 0;
}  // } Driver Code Ends