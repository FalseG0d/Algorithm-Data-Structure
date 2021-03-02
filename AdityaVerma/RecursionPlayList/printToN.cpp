#include <iostream>
using namespace std;

void printToN(int n){
    if(n==0){
        return;
        }
    printToN(n-1);
    cout<<n<<" ";
    
}

int main() {
    printToN(10);
    return 0;
}
