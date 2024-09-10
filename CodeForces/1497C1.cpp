#include <iostream>
using namespace std;
int main() {
    int t;
    cin>>t;

    while(t--) {
        int n,k;
        cin>>n>>k;

        if(n%2 == 1) {
            cout<<n/2<<" "<<n/2<<" "<<1<<"\n";
        } else if(n % 4 == 0) {
            cout<<n/2<<" "<<n/4<<" "<<n/4<<"\n";
        } else {
            cout<<n/2-1<<" "<<n/2-1<<" "<<2<<"\n";
        }
    }

    return 0;
}
