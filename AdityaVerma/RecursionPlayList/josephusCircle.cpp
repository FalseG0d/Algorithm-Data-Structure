#include <bits/stdc++.h>
using namespace std;

int josephusCircle(int k,int itr,vector<int> v){
    if(v.size()==1)return v[0];

    itr+=k-1;
    itr%=v.size();
    
    v.erase(v.begin()+itr);
    
    return josephusCircle(k,itr,v);
}

int main() {
	//code
	int t;
	cin>>t;
	
	while(t--){
	    int n,k;
	    cin>>n>>k;
	    
	    vector<int>v;
	    
	    for(int i=1;i<=n;i++)v.push_back(i);
	    
	    cout<<josephusCircle(k,0,v)<<"\n";
	}
	
	return 0;
}