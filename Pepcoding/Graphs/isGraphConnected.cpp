#include <bits/stdc++.h>
using namespace std;
int main() {
    int V,E;
    cin>>V>>E;

    int src,end,wt;
    vector<int>*graph=new vector<int>[V];

    for(int i=0;i<E;i++){
        cin>>src>>end>>wt;
        graph[src].push_back(end);
    }

    queue<int>que;
    que.push(0);

    bool*visited=new bool[V];
    for(int i=0;i<V;i++) visited[i]=false;

    while(!que.empty()){
        int temp=que.front();

        if(visited[temp]){
            que.pop();
            continue;
        }

        visited[temp]=true;

        for(int i=0;i<graph[temp].size();i++)que.push(graph[temp][i]);
    }

    int count=0;
    for(int i=0;i<V;i++){
        if(visited[i]) count++;
    }

    if(count==V) cout<<"true";
    else cout<<"false";

    return 0;
}
