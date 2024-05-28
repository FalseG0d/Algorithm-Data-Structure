class Solution {
    int M = 0;
    int N = 0;
public:
    void sinkIsland(vector<vector<char>>& grid, int p, int q) {
        if(p == M || q == N || p < 0 || q < 0) return;
        if(grid[p][q] == '0') return;

        grid[p][q] = '0';

        sinkIsland(grid, p+1, q);
        sinkIsland(grid, p, q+1);
        sinkIsland(grid, p-1, q);
        sinkIsland(grid, p, q-1);
    }

    int numIslands(vector<vector<char>>& grid) {
        M = grid.size();
        N = grid[0].size();

        int count = 0;

        for(int i=0;i<M;i++) {
            for(int j=0;j<N;j++) {
                if(grid[i][j] == '1') {
                    count++;
                    sinkIsland(grid, i, j);
                    }
            }
        }

        return count;
    }
};