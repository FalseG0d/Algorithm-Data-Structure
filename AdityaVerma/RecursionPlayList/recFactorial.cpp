#include <iostream>
using namespace std;

int recFactorial(int n){
    if(n==0){
        return 1;
    }
    return n*recFactorial(n-1);
}

int main() {
    int n;
    cin>>n;
    cout<<recFactorial(n);
}
