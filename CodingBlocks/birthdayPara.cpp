#include<iostream>
using namespace std;

int main() {
	float p;
	cin>>p;

	if(p==1){
		cout<<366;
		return 0;
	}

	float num=365;
	float den=365;

	float ans=1;

	while(ans>1.0-p){
		ans=ans*num/den;
		num--;
	}

	cout<<365-num;

	return 0;
}