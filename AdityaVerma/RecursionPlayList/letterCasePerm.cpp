#include <bits/stdc++.h>
using namespace std;

void printCasePermutation(string str,int index,string curr){
    int n=str.length();

    if(index==n-1){
        cout<<curr<<"\n";
        return;
    }

    int i=index+1;
    
    if(str[i]<='z'&&str[i]>='a'){
        curr+=(str[i]-32);
        printCasePermutation(str,i,curr);
        curr.erase(curr.length()-1);
        }else if(str[i]<='Z'&&str[i]>='A'){
            curr+=(str[i]+32);
            printCasePermutation(str,i,curr);
            curr.erase(curr.length()-1);
        }
    curr+=str[i];
    printCasePermutation(str,i,curr);
    curr.erase(curr.length()-1);
    
    return;
}

int main() {
    string str;
    cin>>str;

    printCasePermutation(str,-1,"");

    return 0;
}
