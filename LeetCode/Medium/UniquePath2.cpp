class Solution {
public:
    int uniquePathsWithObstacles(vector<vector<int>>& grid) {
        int M = grid.size();
        int N = grid[0].size();
        long long**dp = new long long*[M];

        for(int i=0;i<M;i++) dp[i] = new long long[N];
        
        bool blocked = false;
        for(int i=M-1;i>=0;i--){
            if(grid[i][N-1] == 1) blocked = true;
            
            if(blocked) dp[i][N - 1] = 0;
            else dp[i][N - 1] = 1;
        }
        
        blocked = false;
        for(int i=N-1;i>=0;i--){
            if(grid[M-1][i] == 1) blocked = true;
            
            if(blocked) dp[M-1][i] = 0;
            else dp[M-1][i] = 1;
        }
        
        for(int i=M-2;i>=0;i--){
            for(int j=N-2;j>=0;j--){                
                if(grid[i][j] == 1){
                    dp[i][j] = 0;

                    continue;
                }
                
                if(i == M - 1 && j == N - 1) continue;
                
                long long rght = j + 1 < N ? dp[i][j+1] : 0;
                long long down = i + 1 < M ? dp[i+1][j] : 0;
                
                dp[i][j] = rght + down;
            }
        }
        
        return dp[0][0];
    }
};