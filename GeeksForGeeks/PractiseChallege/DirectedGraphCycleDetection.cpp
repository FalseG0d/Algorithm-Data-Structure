//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
class Solution {
  public:
    bool*visited;
    bool* dfsVisited;
  
    bool help(int i, vector<int> adj[]){
        if(visited[i]) return true;
        if(dfsVisited[i]) return false;
        
        dfsVisited[i] = visited[i] = true;
        
        for(int ele : adj[i]){
            bool check = help(ele, adj);
            
            if(check) return true;
        }
        
        visited[i] = false;
        return false;
    }
  
    // Function to detect cycle in a directed graph.
    bool isCyclic(int V, vector<int> adj[]) {
        // code here
        
        visited = new bool[V]{false};
        dfsVisited = new bool[V]{false};
        
        for(int i=0;i<V;i++){
            if(dfsVisited[i]) continue;
            
            bool check = help(i, adj);
            
            if(check) return true;
        }
        
        return false;
    }
};

//{ Driver Code Starts.

int main() {

    int t;
    cin >> t;
    while (t--) {
        int V, E;
        cin >> V >> E;

        vector<int> adj[V];

        for (int i = 0; i < E; i++) {
            int u, v;
            cin >> u >> v;
            adj[u].push_back(v);
        }

        Solution obj;
        cout << obj.isCyclic(V, adj) << "\n";
    }

    return 0;
}

// } Driver Code Ends