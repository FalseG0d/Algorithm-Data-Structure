//{ Driver Code Starts
// Initial Template for C++

#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
// User function Template for C++

class Solution {
    bool dfs(int src, vector<bool>& visited, vector<bool>& pathVisited, vector<int> adj[], vector<int>& res) {
        if(pathVisited[src]) return true;
        if(visited[src]) return false;
        
        visited[src] = pathVisited[src] = true;
        bool chk = false;
        
        for(int ele: adj[src]) {
            chk = chk || dfs(ele, visited, pathVisited, adj, res);
        }
        
        pathVisited[src] = false;
        if(!chk) res.push_back(src);
        
        return chk;
    }
  public:
    vector<int> eventualSafeNodes(int V, vector<int> adj[]) {
        // code here
        vector<bool> visited(V, false);
        vector<bool> pathVisited(V, false);
        vector<int> res;
        
        for(int i=0;i<V;i++) {
            if(visited[i]) continue;
            
            int begin = res.size();
            
            dfs(i, visited, pathVisited, adj, res);
        }
        
        sort(res.begin(), res.end());
        
        return res;
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
        vector<int> safeNodes = obj.eventualSafeNodes(V, adj);
        for (auto i : safeNodes) {
            cout << i << " ";
        }
        cout << endl;
    }
}

// } Driver Code Ends