#include <bits/stdc++.h>
using namespace std;

int main() {
    int n;
    cin>>n;

    std:bitset<8>res=std::bitset<8>(-n&n);

    bool flag=false;
    for (int i=res.size()-1;i>=0;i--){
        if(res.test(i)==1)flag=true;
        if(flag)cout<<res.test(i);
        }
    
    return 0;
}
