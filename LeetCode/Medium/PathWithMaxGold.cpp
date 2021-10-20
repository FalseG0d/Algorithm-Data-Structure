class Solution {
public:
    int dfsMax(vector<vector<int>>& grid, int i, int j, int& M, int& N){
        if(i < 0 || j < 0 || i == M || j == N) return 0;
        if(grid[i][j] <= 0) return 0;
        
        grid[i][j] = -grid[i][j];
        
        int add = 0;
        
        add = max(add, dfsMax(grid, i+1, j, M, N));
        add = max(add, dfsMax(grid, i-1, j, M, N));
        add = max(add, dfsMax(grid, i, j+1, M, N));
        add = max(add, dfsMax(grid, i, j-1, M, N));
        
        grid[i][j] = -grid[i][j];
        
        // cout<<"("<<i<<","<<j<<" : "<<grid[i][j]<<" + "<<add<<") -> ";
        
        return grid[i][j] + add;
    }
    int getMaximumGold(vector<vector<int>>& grid) {
        int M = grid.size();
        int N = grid[0].size();
        
        int res = 0;
        
        for(int i=0;i<M;i++){
            for(int j=0;j<N;j++){
                if(grid[i][j] == 0) continue;
                
                res = max(res, dfsMax(grid, i, j, M, N));
                // cout<<res<<"\n";
            }
        }
        
        return res;
    }
};