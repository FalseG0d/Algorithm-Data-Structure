#include <bits/stdc++.h>
using namespace std;
int main() {
    int arr[]={3, 1, 2, 2, 1, 2, 3, 3};
    int k=4;
    int n=sizeof(arr)/sizeof(int);
    
    map<int,int>mp;

    for(int i=0;i<n;i++){
        mp[arr[i]]++;
    }

    for(auto itr=mp.begin();itr!=mp.end();++itr){
        if(itr->second>(n/k)){
            cout<<itr->first<<" ";
        }
    }

    return 0;
}
