#include <bits/stdc++.h>
using namespace std;

int main() {
	//code
	int t;
	cin>>t;
	
	while(t--){
	    int n;
	    cin>>n;
	    vector<int>v;
	    v.push_back(1);
	    
	    while(n>0){
	        int carry=0;
	        int i=0;
	        
    	    for(i=0;i<v.size();i++){
    	        v[i]*=n;
    	        v[i]+=carry;
    	        
    	        carry=v[i]/10;
    	        v[i]%=10;
    	    }
    	    
    	    while(carry>0){
    	        v.push_back(carry%10);
    	        carry/=10;
    	    }
    	    
    	    n--;
	    }
	    
	    for(int i=v.size()-1;i>=0;i--){
	        cout<<v[i];
	    }cout<<"\n";
	}
	
	return 0;
}