#include<iostream>
using namespace std;

int main() {
	int x;
	int y;

	int res=1;

	cin>>x>>y;

	while(y>=1){
		if(y&1)res*=x;

		x*=x;
		y/=2;
	}

	cout<<res;

	return 0;
}