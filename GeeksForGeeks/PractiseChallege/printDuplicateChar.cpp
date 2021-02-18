#include <bits/stdc++.h>
using namespace std;

void printDuplicate(char str[],int n){
    map<char,int>mp;

    for(int i=0;i<n;i++){
        mp[str[i]]++;
    }

    for(auto itr=mp.begin();itr!=mp.end();++itr){
        if(itr->second>1){
            cout<<itr->first<<":"<<itr->second<<"\n";
        }
    }
}

int main() {
    int t;
    cin>>t;
    while(t--){
        int n;
        cin>>n;
        char*str=new char[n];
        for(int i=0;i<n;i++){
            cin>>str[i];
        }
        printDuplicate(str,n);
        cout<<"\n";
    }
}
