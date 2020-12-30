#include <bits/stdc++.h> 
using namespace std;

/*
Definition: Represents graphs with 'V' nodes into an V*V 0-1 Matrix, where A[i][j]=1 means vertex 'i' and 'j' are Connected.

Use when Graph is Dense.

Pros:
1. Easy to implement.
2. Queries over Edge takes O(1) time.

Cons:
1. Comsumes a Lot of Space.	O(V^2)
2. Adding a vertex costs O(V^2) time.

*/

int adj_Mat[10][10];

void add_edge(int u,int v){
    adj_Mat[u][v]=adj_Mat[v][u]=1;
}

void printMatrix(int v){
    cout<<"    ";
    for(int i=0;i<v;i++){
        cout<<i<<" ";
    }cout<<"\n";
    for(int i=0;i<v;i++){
        cout<<i<<"|  ";
        for(int j=0;j<v;j++){
            cout<<adj_Mat[i][j]<<" ";
        }cout<<endl;
    }
}

int main(){
    int v=5;

    add_edge(0, 4);
    add_edge(0, 3);
    add_edge(1, 2);
    add_edge(1, 4);
    add_edge(1, 5);
    add_edge(2, 3);
    add_edge(2, 5);
    add_edge(5, 3);
    add_edge(5, 4);

    printMatrix(v);

    return 0;
}