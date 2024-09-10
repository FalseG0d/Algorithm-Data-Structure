#include <iostream>
using namespace std;
int main() {
    int t;
    cin>>t;

    while(t--) {
        int n,k;
        cin>>n>>k;

        n = n - k + 3;

        if(n % 2 > 0) {
            cout<<1<<" "<<n/2<<" "<<n/2<<" ";
        } else {
            if(n % 4 == 0) {
                cout<<n/2<<" "<<n/4<<" "<<n/4<<" ";
            } else {
                cout<<(n/2 - 1)<<" "<<(n/2 - 1)<<" "<<2<<" ";
            }
        }

        for(int i=0;i<k-3;i++) cout<<1<<" ";
        cout<<"\n";
    }

    return 0;
}
