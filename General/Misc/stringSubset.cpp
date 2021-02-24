#include <iostream>
using namespace std;

void subString(char str[],int l,int r){
    if(l>r){
        for(int i=l;i<r;i++)cout<<str[i];
        cout<<"\n";
    }

    subString(str,l+1,r);
    subString(str,l,r-1);
}

int main() {
    int t;
    cin>>t;
    while(t--){
        int n;
        cin>>n;

        char*str=new char[n];
        for(int i=0;i<n;i++)cin>>str[i];
        
        subString(str,0,n-1);
    }
    return 0;
}
