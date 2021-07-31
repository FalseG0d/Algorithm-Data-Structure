#include <iostream>
#include <vector>

using namespace std;

void drawComp(vector<vector<int>>arr,int i,int j,bool**visited){
    if(i<0 || j<0 || i>=arr.size() || j>=arr[0].size()) return;
    if(arr[i][j] == 1 || visited[i][j]) return;
    
    visited[i][j] = true;

    drawComp(arr,i+1,j,visited);
    drawComp(arr,i-1,j,visited);
    drawComp(arr,i,j+1,visited);
    drawComp(arr,i,j-1,visited);
}

int main() {
    int m,n;
    cin>>m>>n;

    vector<vector<int>>arr(m);
    for(int i=0;i<m;i++) arr[i]=vector<int>(n);

    for(int i=0;i<m;i++){
        for(int j=0;j<n;j++) cin>>arr[i][j];
    }

    bool**visited=new bool*[m];
    for(int i=0;i<m;i++) visited[i]=new bool[n];

    for(int i=0;i<m;i++){
        for(int j=0;j<n;j++) visited[i][j]=false;
    }

    int count=0;

    for(int i=0;i<m;i++){
        for(int j=0;j<n;j++){
            if(arr[i][j]==0 && !visited[i][j]){
                count++;
                drawComp(arr,i,j,visited);
            }
            // cout<<arr[i][j]<<" ";
        }//cout<<"\n";
    }

    cout<<count;

    return 0;
}
