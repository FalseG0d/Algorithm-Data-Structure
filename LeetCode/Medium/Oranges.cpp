class Solution {
public:
    vector<pair<int,int>>getFresh(int p, int q, vector<vector<int>>& grid) {
        int M = grid.size();
        int N = grid[0].size();

        vector<pair<int,int>>res;

        if(p < M-1 && grid[p+1][q] == 1) res.push_back(make_pair(p+1, q));
        if(p > 0 && grid[p-1][q] == 1) res.push_back(make_pair(p-1, q));
        if(q < N-1 && grid[p][q+1] == 1) res.push_back(make_pair(p, q+1));
        if(q > 0 && grid[p][q-1] == 1) res.push_back(make_pair(p, q-1));

        return res;
    }
    int orangesRotting(vector<vector<int>>& grid) {
        // Use BFS
        int M = grid.size();
        int N = grid[0].size();

        queue<pair<int,int>>que;
        int cnt = 0;
        int res = 0;

        for(int i=0;i<M;i++) {
            for(int j=0;j<N;j++) {
                if(grid[i][j] == 2) que.push(make_pair(i, j));
                else if(grid[i][j] == 1) cnt++;
            }
        }

        if(cnt == 0) return 0;
        if(que.empty()) return -1;

        while(!que.empty()) {
            int size = que.size();

            for(int i=0;i<size;i++) {
                pair<int,int>top = que.front();
                que.pop();

                vector<pair<int,int>>freshBatch = getFresh(top.first, top.second, grid);

                for(pair<int,int>batch : freshBatch) {
                    que.push(batch);
                    grid[batch.first][batch.second] = 2;
                    cnt--;
                }
            }

            res++;
        }

        return cnt == 0 ? res - 1 : -1;
    }
};