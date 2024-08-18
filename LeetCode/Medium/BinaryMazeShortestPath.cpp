class Solution {
  public:
    int shortestPath(vector<vector<int>> &grid, pair<int, int> source, pair<int, int> destination) {
        // code here
        if(grid[source.first][source.second] == 0) return -1;
        
        vector<pair<int,int>>moves = {{0, 1}, {0, -1}, {1, 0}, {-1, 0}};
        int M = grid.size();
        int N = grid[0].size();
        
        vector<vector<int>>dij(M, vector<int>(N));
        
        for(int i=0;i<M;i++) {
            for(int j=0;j<N;j++) dij[i][j] = 250001;
        }
        
        priority_queue<pair<int, pair<int,int>>, vector<pair<int, pair<int,int>>>, greater<pair<int, pair<int,int>>>>pq;
        pq.push(make_pair(0, make_pair(source.first, source.second)));
        
        while(!pq.empty()) {
            pair<int, pair<int,int>>top = pq.top();
            pq.pop();
            
            if(dij[top.second.first][top.second.second] > top.first) {
               dij[top.second.first][top.second.second] = top.first;
               
               for(pair<int,int>move: moves) {
                   if(top.second.first + move.first < 0 || top.second.second + move.second < 0 || top.second.first + move.first >= M || top.second.second + move.second >= N) continue;
                   if(grid[top.second.first + move.first][top.second.second + move.second] == 0) continue;
                   
                   pq.push(
                       make_pair(
                           top.first + 1,
                           make_pair(
                               top.second.first + move.first, top.second.second + move.second
                               )
                            )
                        );
               }
            }
        }
        
        if(dij[destination.first][destination.second] == 250001) return -1;
        else return dij[destination.first][destination.second];
    }
};