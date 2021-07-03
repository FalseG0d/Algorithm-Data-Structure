#include<iostream>
using namespace std;

int main() {
	int n;
	cin>>n;

	int res=0;
	int itr=1;

	while(n>0){
		int temp=n%10;
		n/=10;
		
		if(temp==7) res+=itr;

		itr*=2;
	}

	cout<<res+itr-1<<"\n";

	return 0;
}