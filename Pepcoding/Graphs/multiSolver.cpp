#include<bits/stdc++.h>
using namespace std;

typedef pair<int,int> pp;

vector<int>path;
bool*visited;

vector<pair<int,vector<int>>>res;

void save(int wt){
    res.push_back(make_pair(wt,path));
}

void print(vector<int>v){
    for(auto itr=v.begin();itr!=v.end();++itr) cout<<*itr;
}

void multiSolver(vector<pp>*v,int src,int end,int wt){
    if(src == end){
        save(wt);
        return;
        }
    
    for(int i=0;i<v[src].size();i++){
        if(visited[v[src][i].first]) continue;

        path.push_back(v[src][i].first);
        visited[v[src][i].first]=true;

        multiSolver(v,v[src][i].first,end,wt+v[src][i].second);
        
        path.pop_back();
        visited[v[src][i].first]=false;
    }

    return;
}

int main(){
    int v,e;
    cin>>v>>e;
    
    vector<pp>*vertex=new vector<pp>[v];
    
    for(int i=0;i<e;i++){
        int src,end,wt;
        cin>>src>>end>>wt;
        
        vertex[src].push_back(make_pair(end,wt));
        vertex[end].push_back(make_pair(src,wt));
    }
    
    int src,end;
    cin>>src>>end;
    
    int crit,k;
    cin>>crit>>k;

    visited=new bool[v];
    for(int i=0;i<v;i++) visited[i]=false;
    
    visited[src]=true;
    path.push_back(src);
    multiSolver(vertex,src,end,0);
    
    sort(res.begin(),res.end());
    
    int n=res.size();
    
    cout<<"Smallest Path = ";
    print(res[0].second);
    cout<<"@"<<res[0].first;
    cout<<"Largest Path = ";
    print(res[n-1].second);
    cout<<"@"<<res[n-1].first;
    cout<<k<<"th Path = ";
    print(res[n-k].second);
    cout<<"@"<<res[n-1].first;
    
    
    return 0;
}