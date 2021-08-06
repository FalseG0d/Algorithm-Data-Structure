#include<bits/stdc++.h>
using namespace std;

int main(){
    int n1;
    cin>>n1;

    int*arr1=new int[n1];
    for(int i=0;i<n1;i++) cin>>arr1[i];
    
    int n2;
    cin>>n2;

    int*arr2=new int[n2];
    for(int i=0;i<n2;i++) cin>>arr2[i];

    map<int,int>mp;

    for(int i=0;i<n1;i++)mp[arr1[i]]++;
    for(int i=0;i<n2;i++){
        if(mp[arr2[i]]>=1) cout<<arr2[i]<<"\n";
        mp[arr2[i]]--;
    }
    
    return 0;
}