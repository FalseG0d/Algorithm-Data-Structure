class Solution {
public:
    bool isClosed(vector<vector<int>>& grid, int i, int j, int M, int N){
        if(grid[i][j] == 1 || grid[i][j] == -1) return true;
        if(i == 0 || j == 0 || i == M-1|| j == N-1) return false;
        
        grid[i][j] = -1;
        bool res = true;
        
        if(!isClosed(grid,i-1,j,M,N)) res &= false;
        if(!isClosed(grid,i+1,j,M,N)) res &= false;
        if(!isClosed(grid,i,j-1,M,N)) res &= false;
        if(!isClosed(grid,i,j+1,M,N)) res &= false;
        
        return res;
    }
    
    int closedIsland(vector<vector<int>>& grid) {
        int M = grid.size();
        int N = grid[0].size();
        
        int res = 0;
        
        for(int i=0;i<M;i++){
            for(int j=0;j<N;j++){
                if(grid[i][j] == 1 || grid[i][j] == -1) continue;
                
                if(isClosed(grid,i,j,M,N)){
                    res++;
                    // cout<<i<<","<<j<<":"<<res<<"\n";
                }
            }
        }
        
        return res;
    }
};