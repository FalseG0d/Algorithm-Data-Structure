#include<iostream>
using namespace std;

bool isPrime(int N){
	for(int i=2;i<N/2;i++){
		if(N%i==0)return false;
	}

	return true;
}

int digitSum(int N){
	int digSum=0;

	while(N>0){
		digSum+=(N%10);
		N/=10;
	}

	return digSum;
}

int main() {
	int N;
	cin>>N;

	if(isPrime(N)){
		cout<<0;
		return 0;
	}

	int NCopy=N;

	int factorSum=0;

	for(int i=2;i<=N;i++){		
		while(N%i==0){
			N/=i;
			factorSum+=digitSum(i);
		}
	}

	N=NCopy;

	int digSum=digitSum(N);

	if(digSum==factorSum)cout<<1;
	else cout<<0;

	return 0;
}