#include <bits/stdc++.h>
using namespace std;

int chocolateDist(int n,int*arr,int m){
    int res=INT_MAX;
    
    // int avg=0;
    // for(int i=0;i<n;i++){
    //     avg+=arr[i];
    // }
    
    // avg/=n;
    
    // for(int i=0;i<n;i++){
    //     arr[i]-=avg;
    //     arr[i]=max(arr[i],-arr[i]);
    // }
    
    sort(arr,arr+n);
    
    // for(int i=0;i<n;i++){
    //     cout<<arr[i]<<" ";
    // }cout<<"\n";
    
    for(int i=0;i<=n-m;i++){
        res=min(res,arr[i+m-1]-arr[i]);
        // cout<<res<<" ";
    }//cout<<"\n";
    
    // res=arr[m-1]-arr[0];
    
    return res;
}

int main() {
	//code
	int t;
	cin>>t;
	
	while(t--){
	    int n;
	    cin>>n;
	    int*arr=new int[n];
	    
	    for(int i=0;i<n;i++){
	        cin>>arr[i];
	    }
	    
	    int m;
	    cin>>m;
	    
	    cout<<chocolateDist(n,arr,m)<<"\n";
	}
	return 0;
}