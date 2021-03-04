#include <bits/stdc++.h>
using namespace std;

void nPairParan(int left,int right,string curr){
    if(right<left||left<0||right<0)return;
    if(right==0){cout<<curr<<"\n";return;}

    curr+="(";
    nPairParan(left-1,right,curr);
    curr.erase(curr.length()-1);
    curr+=")";
    nPairParan(left,right-1,curr);
}

int main() {
    int n;
    cin>>n;

    nPairParan(n,n,"");

    return 0;
}
