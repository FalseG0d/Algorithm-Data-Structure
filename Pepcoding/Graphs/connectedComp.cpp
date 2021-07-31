#include<bits/stdc++.h>
using namespace std;

int main(){
    int v,e;
    cin>>v>>e;
    
    vector<int>*graph=new vector<int>[v];
    
    int src,end,wt;
    for(int i=0;i<e;i++){
        cin>>src>>end>>wt;
        
        graph[src].push_back(end);
    }
    
    bool*visited=new bool[v];
    for(int i=0;i<v;i++) visited[i]=false;

    vector<vector<int>>res;
    
    for(int i=0;i<v;i++){
        if(visited[i]) continue;
        
        queue<int>que;
        que.push(i);

        vector<int>comp;
        
        while(!que.empty()){
            int temp=que.front();

            if(visited[temp]){
                que.pop();
                continue;
                }
            
            visited[temp]=true;
            comp.push_back(temp);
            for(int i=0;i<graph[temp].size();i++) que.push(graph[temp][i]);
        }
        
        sort(comp.begin(),comp.end());
        res.push_back(comp);
    }

    int n1=res.size();
    cout<<"[";
    for(int i=0;i<n1;i++){
        cout<<"[";
        int n2=res[i].size();
        for(int j=0;j<n2;j++){
            cout<<res[i][j];
            if(j<n2-1)cout<<", ";
            }
        cout<<"]";
        if(i<n1-1)cout<<", ";
    }
    cout<<"]";
    
    return 0;
}