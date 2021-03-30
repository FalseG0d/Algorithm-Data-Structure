#include <bits/stdc++.h>
using namespace std;

vector<int>bellmannFord(vector<vector<int>>graph,int edge,int node){
    vector<int>res;
    res.push_back(0);

    for(int i=1;i<node;i++){
        res.push_back(10000);
    }

    for(int i=0;i<node;i++)cout<<res[i]<<" ";

    cout<<"\n";

    for(int i=0;i<edge-1;i++){
        for(int j=0;j<edge;j++){
            res[graph[j][1]]=min(res[graph[j][1]],res[graph[j][0]]+graph[j][2]);
        }
    }

    for(int i=0;i<node;i++)cout<<res[i]<<" ";

    return res;
}

int main() {
    vector<vector<int>>graph;
    int edge,node;
    cin>>edge>>node;

    for(int i=0;i<edge;i++){
        vector<int>tempEdge;
        int val;

        for(int j=0;j<3;j++){
            cin>>val;
            tempEdge.push_back(val);
            }
        
        graph.push_back(tempEdge);
    }

    vector<int>res=bellmannFord(graph,edge,node);

    return 0;
}
