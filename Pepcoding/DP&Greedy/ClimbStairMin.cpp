#include<bits/stdc++.h>
using namespace std;

int*dp;

int csMinStep(int n,int pos,int arr[]){
	if(pos>=n)return 0;
	if(dp[pos]!=-1)return dp[pos];

	int val=INT_MAX;
	
	for(int i=0;i<=arr[pos];i++)dp[pos]=min(val,1+csMin(pos+i));

	return 1+dp[pos];
}

int main(){
	int n;
	cin>>n;
	dp=new int[n+1];
	for(int i=0;i<=n;i++)dp[i]=-1;
	dp[n]=0;

	int*arr=new int[n];
	for(int i=0;i<n;i++)cin>>arr[i];

	cout<<csMinStep(n,0,arr);

	return 0;
}
