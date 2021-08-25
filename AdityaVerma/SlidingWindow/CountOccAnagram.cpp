// { Driver Code Starts
#include <bits/stdc++.h>

using namespace std;


 // } Driver Code Ends
//User function template for C++
class Solution{
public:
	int search(string pat, string txt) {
	    // code here
	    int mp[256]{0};
	    int res = 0;
	    
	    long long int hash = 0;
	    long long int temp = 0;
	    
	    for(char ch:pat){
	        hash += ch;
	        mp[ch]++;
	    }
	    
	    int N = txt.length();
	    int K = pat.length();
	    
	    int left = 0;
	    int right= 0;
	    
	    while(right < N){
	        temp += txt[right];
	        if(right - left == K) temp -= txt[left++];
	        
	        if(temp == hash){
	            // Check if Anagram
	            int tmp[256]{0};
	            bool ana = true;
	            
	            for(int i=left;i<=right;i++) tmp[txt[i]]++;
	            
	            for(int i=0;i<256;i++){
	                if(tmp[i] != mp[i]){
	                    ana = false;
	                    break;
	                }
	            }
	            
	            if(ana) res++;
	        }
	        
	        right++;
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