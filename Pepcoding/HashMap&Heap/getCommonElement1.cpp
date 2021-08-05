#include<bits/stdc++.h>
using namespace std;

int main(){
    int n1;
    cin>>n1;
    
    map<int,int>mp;
    
    int temp;
    for(int i=0;i<n1;i++){
        cin>>temp;
        
        mp[temp]++;
        if(mp[temp]>=2) mp[temp]=1;
    }
    
    int n2;
    cin>>n2;
    
    for(int i=0;i<n2;i++){
        cin>>temp;
        mp[temp]++;
        
        if(mp[temp]==1) mp[temp]=0;
        if(mp[temp]==2) cout<<temp<<"\n";
    }
    
    return 0;
}