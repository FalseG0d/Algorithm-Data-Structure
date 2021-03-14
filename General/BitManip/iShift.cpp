#include <iostream>
using namespace std;

int binaryLeftShift(int n,int i){
    return n<<i;
}

int binaryRightShift(int n,int i){
    return n>>i;
}

int main() {
    int t;
    cin>>t;

    while(t--){
        int n;
        cin>>n;

        int i;
        cin>>i;

        cout<<"Left Shift: "<<binaryLeftShift(n,i)<<"\n";
        cout<<"Right Shift: "<<binaryRightShift(n,i)<<"\n";
    }

    return 0;
}
