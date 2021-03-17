#include <bits/stdc++.h>
using namespace std;

string ithBitSet(int n,int i){
    int x=1;
    x=x<<i;

    int res=n&x;

    if(res==0)return "Not Set";
    else return "Is Set";
}

int main() {
    int n,i;

    cin>>n>>i;
    cout<<ithBitSet(n,i);

    return 0;
}
