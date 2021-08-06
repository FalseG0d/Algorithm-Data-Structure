#include<bits/stdc++.h>
using namespace std;

int main(){
    int n;
    cin>>n;
    
    vector<vector<int>>v;
    int maxLen=-1;
    
    for(int i=0;i<n;i++){
        int temp_S;
        cin>>temp_S;
        
        vector<int>temp_V(temp_S);
        for(int i=0;i<temp_S;i++) cin>>temp_V[i];
        
        v.push_back(temp_V);
        
        maxLen=max(maxLen,temp_S);
    }
    
    int itr=0;
    priority_queue<int,vector<int>,greater<int>>pq;
    
    do{
        for(int i=0;i<n;i++){
            if(itr<v[i].size()) pq.push(v[i][itr]);
        }
        
        cout<<pq.top()<<" ";
        pq.pop();
        
        itr++;
    }while(!pq.empty());
    
    return 0;
}