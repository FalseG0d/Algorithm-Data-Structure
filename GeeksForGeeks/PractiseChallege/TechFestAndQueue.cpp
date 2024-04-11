//{ Driver Code Starts

#include<bits/stdc++.h>
using namespace std;

// } Driver Code Ends

class Solution {
public:
	int sumOfPowers(int a, int b){
	    // Code here
	    vector<int>sieve(b+1, 0);
	    
	    for(int i=2;i<=b;i++) {
	        if(!sieve[i]) {
	            for(int j=i;j<=b;j+=i) {
	                int div = j;
	                
	                while(div > 1) {
	                    if(div % i) break;
	                    
	                    sieve[j]++;
	                   // cout<<j<<": "<<sieve[j]<<"\n";
	                    div /= i;
	                }
	            }
	        }
	    }
	    
	    int res = 0;
	    for(int i=a;i<=b;i++) res += sieve[i];
	    
	    
	   // for(int i=0;i<=b;i++) cout<<i<<"\t";
	   // cout<<"\n";
	   // for(int i=0;i<=b;i++) cout<<sieve[i]<<"\t";
	   // cout<<"\n";
	    
	    return res;
	}
};

//{ Driver Code Starts.
int main(){
	int tc;
	cin >> tc;
	while(tc--){
		int a, b;
		cin >>  a >> b;
		Solution obj;
		int ans = obj.sumOfPowers(a, b);
		cout << ans <<"\n";
	}
	return 0;
}
// } Driver Code Ends