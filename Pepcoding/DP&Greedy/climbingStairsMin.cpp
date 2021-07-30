#include<bits/stdc++.h>
using namespace std;

int*dp;

int csMinStep(int n,int pos,int arr[]){
    if(pos>=n)return 0;
    if(arr[pos]==0)return 1000-1;
    
    int res=csMinStep(n,pos+1,arr);;

    for(int i=arr[pos];i>=2;i--){
        int val=csMinStep(n,pos+i,arr);
        res=min(res,val);
        }
    // cout<<pos+1<<":"<<res<<"\n";

	return 1+res;
}

int main(){
	int n;
	cin>>n;
	dp=new int[n+1];
	for(int i=0;i<=n;i++)dp[i]=1000;
	dp[n]=0;

	int*arr=new int[n];
	for(int i=0;i<n;i++)cin>>arr[i];

	cout<<csMinStep(n,0,arr);
	return 0;
}
