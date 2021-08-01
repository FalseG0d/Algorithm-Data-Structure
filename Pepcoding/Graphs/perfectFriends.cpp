#include <iostream>
#include <vector>
#include <queue>
using namespace std;

int main() {
    int V,E;
    cin>>V>>E;

    vector<int>*graph=new vector<int>[V];
    int src,end,wt;

    for(int i=0;i<E;i++){
        cin>>src>>end;

        graph[src].push_back(end);
        graph[end].push_back(src);
    }

    bool*visited=new bool[V];
    for(int i=0;i<V;i++) visited[i]=false;

    vector<vector<int>>clubs;

    for(int i=0;i<V;i++){
        if(visited[i]) continue;

        queue<int>que;
        que.push(i);

        vector<int>comp;

        while(!que.empty()){
            int temp=que.front();
            if(visited[temp]) {
                que.pop();
                continue;
                }
            
            visited[temp]=true;
            comp.push_back(temp);
            for(int i=0;i<graph[temp].size();i++){
                que.push(graph[temp][i]);
                }
        }

        clubs.push_back(comp);
    }

    int no_Clubs=clubs.size();
    int res=0;

    for(int i=0;i<no_Clubs-1;i++){
        for(int j=i+1;j<no_Clubs;j++){
            res+=clubs[i].size()*clubs[j].size();
        }
    }

    cout<<res;

    return 0;
}