#include <bits/stdc++.h>
using namespace std;

int kthGrammar(int n,int k){
    if(n==1)return 0;

    int len=pow(2,n-1);

    if(k<len/2){
        return kthGrammar(n-1,k);
    }else{
        return kthGrammar(n-1,k-len/2)==1?0:1;
    }
}

int solve(int n,int k){
    return kthGrammar(n,k-1);
}

int main() {
    int n,k;
    cin>>n>>k;

    cout<<solve(n,k);

    return 0;
}
