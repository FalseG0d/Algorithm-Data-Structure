#include <bits/stdc++.h>
using namespace std;

int main() {
	//code
	int t;
	cin>>t;
	
	while(t--){
	    int n1,n2;
	    cin>>n1>>n2;
	    int flag=0;
	    map<int,int> m;
	    
	    for(int i=0;i<n1;i++){
	        int temp;
	        cin>>temp;
	        m[temp]++;
	    }
	    
	    for(int i=0;i<n2;i++){
	        int temp;
	        cin>>temp;
	        
	        if(m[temp]==0){
	            cout<<"No\n";
                flag=1;
	            break;
	        }
	    }
	    
        if(flag==0)
	        cout<<"Yes\n";
	}
	
	return 0;
}