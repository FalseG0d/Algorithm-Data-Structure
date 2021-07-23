#include <bits/stdc++.h>
using namespace std;

void printSort(vector<int>v,int k){
    priority_queue<int,vector<int>,greater<int>>pq;
    
    for(int i=0;i<k;i++)pq.push(v[i]);
    
    for(int i=0;i<v.size()-k;i++){
        cout<<pq.top()<<" ";
        pq.pop();
        
        pq.push(v[i+k]);
    }
    
    while(!pq.empty()){
        cout<<pq.top()<<" ";
        pq.pop();
    }
    
    cout<<"\n";
    
    return;
}

int main() {
	//code
	int t;
	cin>>t;
	
	while(t--){
	    int n,k;
	    cin>>n>>k;
	    
	    vector<int>v(n);
	    
	    for(int i=0;i<n;i++){
	        cin>>v[i];
	    }
	    
	    printSort(v,k);
	}
	
	return 0;
}