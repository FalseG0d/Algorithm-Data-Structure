#include<bits/stdc++.h>
using namespace std;

int main(){
    int n;
    cin>>n;

    int*arr=new int[n];
    for(int i=0;i<n;i++) cin>>arr[i];
    
    map<int,bool>mp;
    for(int i=0;i<n;i++) mp[arr[i]]=true;
    
    for(int i=0;i<n;i++){
        int key=arr[i];
        if(mp.find(key-1) != mp.end()) mp[key]=false;
    }
    
    int m_stp=0;
    int m_len=0;

    for(int i=0;i<n;i++){
        if(mp[arr[i]]){
            int temp_stp=arr[i];
            int temp_len=1;
            
            while(mp.find(temp_stp+temp_len)!=mp.end()) temp_len++;
            
            if(temp_len>m_len){
                m_stp=temp_stp;
                m_len=temp_len;
            }
        }
    }
    
    for(int i=0;i<m_len;i++) cout<<m_stp+i<<"\n";
    
    return 0;
}