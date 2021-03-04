#include <bits/stdc++.h>
using namespace std;

void printPermutation(string str,int index,string curr){
    int n=str.length();

    if(index==n-1){cout<<curr<<"\n";return;}

    for(int i=index+1;i<n;i++){
        curr+=str[i];
        curr+=" ";
        printPermutation(str,i,curr);
        curr.erase(curr.length()-1);
    }

    return;
}

int main() {
    string str;
    cin>>str;

    printPermutation(str,-1,"");

    return 0;
}
