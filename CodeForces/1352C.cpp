#include <iostream>
using namespace std;
int main() {
    int t;
    cin>>t;

    while(t--) {
        int n,k;
        cin>>n>>k;

        if(k < n) cout<<k<<"\n";
        else {
            int res = k + k / (n-1);

            if(res % n) cout<<res<<"\n";
            else cout<<res-1<<"\n";
        }

    }

    return 0;
}