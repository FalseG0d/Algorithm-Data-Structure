//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
class Solution {
  public:
    // Function to return a list containing the DFS traversal of the graph.
    vector<int> dfsOfGraph(int V, vector<int> adj[]) {
        // Code here
        vector<int>res;
        vector<bool>visited(V, false);
        
        stack<int>st;
        int prev = -1;
        
        st.push(0);
        
        while(!st.empty()) {
            int top = st.top();
            st.pop();
            
            if(visited[top]) continue;
            
            res.push_back(top);
            visited[top] = true;
            
            int n = adj[top].size();
            
            for(int i=n-1;i>=0;i--) {
                int ele = adj[top][i];
                
                if(ele == top || ele == prev) continue;
                
                st.push(ele);
            }
            
            prev = top;
        }
        
        return res;
    }
};

//{ Driver Code Starts.
int main() {
    int tc;
    cin >> tc;
    while (tc--) {
        int V, E;
        cin >> V >> E;

        vector<int> adj[V];

        for (int i = 0; i < E; i++) {
            int u, v;
            cin >> u >> v;
            adj[u].push_back(v);
            adj[v].push_back(u);
        }
        // string s1;
        // cin>>s1;
        Solution obj;
        vector<int> ans = obj.dfsOfGraph(V, adj);
        for (int i = 0; i < ans.size(); i++) {
            cout << ans[i] << " ";
        }
        cout << endl;
    }
    return 0;
}
// } Driver Code Ends