#include <bits/stdc++.h>
using namespace std;

class Graph{
    int V;
    list<int>*adj;
    
    public:

    Graph(int V){
        this->V=V;
        this->adj=new list<int>[V];
    }

    void addEdge(int s,int e){
        adj[s].push_back(e);
    }

    void print(){
        for(int i=0;i<V;i++){
            cout<<i<<": ";
            for(auto j=adj[i].begin();j!=adj[i].end();++j)cout<<*j<<", ";
            cout<<"\n";
        }
    }

    void BFS(int s){
        bool*visited=new bool[V]{false};

        queue<int>que;
        que.push(s);

        while(!que.empty()){
            int temp=que.front();
            que.pop();

            if(visited[temp])continue;

            visited[temp]=true;
            cout<<temp<<", ";

            for(auto itr=adj[temp].begin();itr!=adj[temp].end();++itr){
                if(visited[*itr]) continue;
                else que.push(*itr);
                }
        }
    }
};

int main() {
    int n;
    cin>>n;

    Graph g(n);

    g.addEdge(0, 1);
    g.addEdge(0, 2);
    g.addEdge(1, 2);
    g.addEdge(2, 0);
    g.addEdge(2, 3);
    g.addEdge(3, 3);

    // g.print();
    g.BFS(2);

    return 0;
}