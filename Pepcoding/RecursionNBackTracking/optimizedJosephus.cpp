#include<bits/stdc++.h>
using namespace std;

int josephus(int n,int k){
    if(n==1)return 0;

    int currPos=josephus(n-1,k);
    // cout<<currPos<<" ";
    return (currPos+k)%n;
}

int main(){
    int n,k;
    cin>>n>>k;

    cout<<josephus(n,k);

    return 0;
}