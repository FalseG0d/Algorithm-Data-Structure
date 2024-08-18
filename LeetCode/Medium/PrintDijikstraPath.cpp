class Solution {
  public:
    vector<int> shortestPath(int V, int m, vector<vector<int>>& edges) {
        // Code here
        vector<vector<pair<int, int>>>adj(V);
        
        for(int i=0;i<m;i++) {
            adj[edges[i][0]-1].push_back(make_pair(edges[i][1]-1, edges[i][2]));
            adj[edges[i][1]-1].push_back(make_pair(edges[i][0]-1, edges[i][2]));
        }
        vector<int>res(V, INT_MAX);
        vector<int>par(V, -1);
        
        priority_queue<vector<int>, vector<vector<int>>, greater<vector<int>>>pq;
        pq.push({0, 0, -1});
        
        while(!pq.empty()) {
            vector<int>top = pq.top();
            pq.pop();
            
            int dist = top[0];
            int curr = top[1];
            int prev = top[2];
            
            if(res[curr] > dist) {
                res[curr] = dist;
                par[curr] = prev;
                
                for(pair<int,int> edge: adj[curr]) {
                    pq.push({dist + edge.second, edge.first, curr});
                }
            }
        }
        
        if(par[V-1] == -1) return {-1};
        
        vector<int>dij;
        
        dij.push_back(res[V-1]);
        int itr = V-1;
        
        dij.push_back(V);
        
        while(par[itr] != -1) {
            dij.push_back(par[itr] + 1);
            itr = par[itr];
        }
        
        reverse(dij.begin() + 1, dij.end());
        
        // for(int ele: dij) cout<<ele<<" ";
        // cout<<"\n";
        
        
        return dij;
    }
};