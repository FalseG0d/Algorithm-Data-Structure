#include <bits/stdc++.h>
using namespace std;

int main() {
    int n,res,count=0;
    cin>>n;

    while(n>0){
        count++;
        res=n&(-n);
        n-=res;
    }

    cout<<count;
    
    return 0;
}
