#include <iostream>
using namespace std;
int main() {
    int t;
    cin>>t;

    int primes[]={2,3,5,7,11,13,17,19};

    while(t--){
        int n;
        cin>>n;

        int res=0;

        int no_of_sets=(1<<8)-1;

        for(int i=1;i<=no_of_sets;i++){
            int denom=1;

            for(int j=0;j<8;j++){
                if(i&(1<<j)){
                    denom*=primes[j];
                }
            }
            int no_of_bits=__builtin_popcount(i);

            if(no_of_bits%2==1)res+=(n/denom);
            else res-=(n/denom);
        }

        cout<<res<<endl;
    }

    return 0;
}
