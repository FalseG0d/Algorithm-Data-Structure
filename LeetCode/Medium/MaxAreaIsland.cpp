class Solution {
public:
    int areaDFS(vector<vector<int>>& grid, int i, int j, int M, int N){
        if(i < 0 || j < 0 || i == M || j == N) return 0;
        if(grid[i][j] == 0) return 0;
        
        grid[i][j] = 0;
        
        return 1 + areaDFS(grid,i-1,j,M,N) + areaDFS(grid,i+1,j,M,N) + areaDFS(grid,i,j-1,M,N) + areaDFS(grid,i,j+1,M,N);
    }
    
    int maxAreaOfIsland(vector<vector<int>>& grid) {
        int M = grid.size();
        int N = grid[0].size();
        
        int res = 0;
        
        for(int i=0;i<M;i++){
            for(int j=0;j<N;j++){
                if(grid[i][j] == 1) res = max(res, areaDFS(grid, i, j, M, N));
            }
        }
        
        return res;
    }
};