#include<bits/stdc++.h>

using namespace std;

/*
Definition: An array of LL or Vector is used. The size of Array is equal to the number of Vertices.

Pros:
1. Saves space O(|V|+|E|), worst case O(V^2).
2. Adding Vertex is Easy.

Cons:

1. Queries costs O(V) time.

*/

void addEdge(vector<int> adj[],int u,int v){
	adj[u].push_back(v);
	adj[v].push_back(u);
}

void printGraph(vector<int> adj[],int V){
	for(int v=0;v<V;v++){
		cout<<"Adjacency List of "<<v;
		for(auto x:adj[v]){
			cout<<"->"<<x;
		}cout<<endl;
	}
}

int main(){
	int V=5;
	vector<int> adj[V];
	addEdge(adj,0,1); 
    addEdge(adj, 0, 4); 
    addEdge(adj, 1, 2); 
    addEdge(adj, 1, 3); 
    addEdge(adj, 1, 4); 
    addEdge(adj, 2, 3); 
    addEdge(adj, 3, 4); 
    printGraph(adj, V); 
    return 0;
}