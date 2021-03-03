#include <bits/stdc++.h>
using namespace std;

void toh(int n,int s,int h,int d){
    if(n==1){
        cout<<"Move 1 from "<<s<<" to "<<d<<"\n";
        return;
    }

    toh(n-1,s,d,h);
    cout<<"Move "<<n<<" from "<<s<<" to "<<d<<"\n";
    toh(n-1,h,s,d);
}

int main() {
    int n;
    cin>>n;

    toh(n,1,2,3);//S->1,H->2,D->3

    return 0;
}
