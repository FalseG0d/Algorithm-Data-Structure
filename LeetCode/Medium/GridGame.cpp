class Solution {
public:
    long long gridGame(vector<vector<int>>& temp) {
        int N = temp[0].size();
        
        vector<vector<long long>>grid(2, vector<long long>(N, 0));
        
        for(int i=0;i<2;i++){
            for(int j=0;j<N;j++) grid[i][j] = temp[i][j];
        }
        
        for(int i=N-2;i>=0;i--) grid[0][i] += grid[0][i+1];
        for(int i=N-2;i>=0;i--) grid[1][i] += grid[1][i+1];
        
        
        long long robot2 = LONG_MAX;
        for(int i=0;i<N;i++){
            if(i == N-1) robot2 = min(robot2, grid[1][0] - grid[1][i]);
            else robot2 = min(robot2, max(grid[0][i+1], grid[1][0] - grid[1][i]));
            
            // cout<<i<<":"<<robot2<<"\n";
        }
        
        return robot2;
    }
};