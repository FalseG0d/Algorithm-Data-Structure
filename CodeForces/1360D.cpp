#include <iostream>
using namespace std;
int main() {
    int t;
    cin>>t;

    while(t--) {
        int n,k;
        cin>>n>>k;

        if(n<=k) {
            cout<<"1\n";
            continue;
        }

        int root = 1;
        while(root * root <= n) root++;

        root = min(root, k);
        int res = n;

        for(int i=2;i<=root;i++) {
            if(n % i == 0) {
                res = min(res, min(i, n/i));
            }
        }

        cout<<res<<"\n";
    }

    return 0;
}
