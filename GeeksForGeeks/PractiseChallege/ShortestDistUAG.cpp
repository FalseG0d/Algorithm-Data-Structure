//{ Driver Code Starts
// Initial Template for C++

#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
// User function Template for C++
class Solution {
  public:
    vector<int> shortestPath(vector<vector<int>>& edges, int N,int M, int src){
        // code here
        unordered_map<int,vector<int>>graph;
        
        for(vector<int>edge: edges) {
            graph[edge[0]].push_back(edge[1]);
            graph[edge[1]].push_back(edge[0]);
        }
        
        vector<int>visited(N, false);
        vector<int>dist(N, 10001);
        
        queue<int>que;
        que.push(src);
        
        dist[src] = 0;
        visited[src] = true;
        
        while(!que.empty()) {
            int front = que.front();
            que.pop();
            
            for(int neighbor: graph[front]) {
                if(dist[neighbor] > dist[front] + 1) {
                    dist[neighbor] = dist[front] + 1;
                    que.push(neighbor);
                }
            }
        }
        
        for(int i=0;i<N;i++) {
            if(dist[i] == 10001) dist[i] = -1;
        }
        
        return dist;
    }
};


//{ Driver Code Starts.
int main() {
    int t;
    cin >> t;
    while (t--) {
        int n, m; cin >> n >> m;
        vector<vector<int>> edges;

        for (int i = 0; i < m; ++i) {
            vector<int> temp;
            for(int j=0; j<2; ++j){
                int x; cin>>x;
                temp.push_back(x);
            }
            edges.push_back(temp);
        }

        int src; cin >> src;

        Solution obj;

        vector<int> res = obj.shortestPath(edges, n, m, src);

        for (auto x : res){
            cout<<x<<" ";
        }
        cout << "\n";
    }
}

// } Driver Code Ends