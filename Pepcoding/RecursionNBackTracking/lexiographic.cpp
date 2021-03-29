#include<bits/stdc++.h>
using namespace std;

void lexiographic(int x,int n){
    if(x>n)return;
    int i=0;

    while(x<=n&&i<10){
        if(x!=0){
            cout<<x<<"\n";
            lexiographic(x*10,n);
            }
        x++;i++;
    }
}

int main(){
    int n;
    cin>>n;

    lexiographic(0,n);

    return 0;
}