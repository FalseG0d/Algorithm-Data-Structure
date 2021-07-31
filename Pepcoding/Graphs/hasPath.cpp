#include<bits/stdc++.h>
using namespace std;

int main(){
    int v,e;
    cin>>v>>e;
    
    vector<int>*vertex=new vector<int>[v];
    
    for(int i=0;i<e;i++){
        int src,end,wt;
        cin>>src>>end>>wt;
        
        vertex[src].push_back(end);
    }
    
    int src,end;
    cin>>src>>end;
    
    queue<int>que;
    que.push(src);
    
    bool*visited=new bool[v];
    
    while(!que.empty()){
        int temp=que.front();
        
        if(temp==end){
            cout<<"true";
            return 0;
        }
        
        if(visited[temp]){
            que.pop();
            continue;
        }else{
            visited[temp]=true;
        }
        
        for(int i=0;i<vertex[temp].size();i++)que.push(vertex[temp][i]);
    }
    
    cout<<"false";
    
    return 0;
}