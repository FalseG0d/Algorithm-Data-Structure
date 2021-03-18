#include <bits/stdc++.h>
using namespace std;

int noOfSetBits(int n){
    int count=0;
    int x=1;

    while(x<n){
        int check=x&n;
        x=x<<1;
        if(check!=0)count++;
    }

    return count;
}

int main() {
    int n;

    cin>>n;
    cout<<noOfSetBits(n);

    return 0;
}
