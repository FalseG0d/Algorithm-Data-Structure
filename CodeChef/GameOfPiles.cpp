#include <iostream>
using namespace std;

int main() {
    int T;
    cin>>T;

    while(T--){
        int N;
        cin>>N;
        int *arr = new int[N];
        for(int i=0;i<N;i++) cin>>arr[i];

        long long sum = 0;

        for(int i=0;i<N;i++){
            if(arr[i] == 1){
                sum = 1;
                break;
            }

            sum += (arr[i] % 2);
        }
        
        // cout<<sum<<": ";

        if(sum % 2 == 0) cout<<"CHEFINA\n";
        else cout<<"CHEF\n";
    }

    return 0;
}
