#include<bits/stdc++.h>
using namespace std;

vector<int>path;
bool*visited;

void print(){
    for(int i=0;i<path.size();i++)cout<<path[i];
    cout<<"\n";
}

void printAllPath(vector<int>*v,int src,int end){
    if(src == end){
        print();
        return;
        }
    
    for(int i=0;i<v[src].size();i++){
        if(visited[v[src][i]]) continue;

        path.push_back(v[src][i]);
        visited[v[src][i]]=true;

        printAllPath(v,v[src][i],end);
        
        path.pop_back();
        visited[v[src][i]]=false;
    }

    return;
}

int main(){
    int v,e;
    cin>>v>>e;
    
    vector<int>*vertex=new vector<int>[v];
    
    for(int i=0;i<e;i++){
        int src,end,wt;
        cin>>src>>end>>wt;
        
        vertex[src].push_back(end);
        vertex[end].push_back(src);
    }
    
    int src,end;
    cin>>src>>end;

    visited=new bool[v];
    for(int i=0;i<v;i++) visited[i]=false;
    
    visited[src]=true;
    path.push_back(src);
    printAllPath(vertex,src,end);
    
    return 0;
}