class Solution {
public:
    int help(int p, int q, vector<vector<int>>& obstacleGrid) {
        if(p == obstacleGrid.size() || q == obstacleGrid[0].size()) return 0;
        if(p == obstacleGrid.size() - 1 && q == obstacleGrid[0].size() - 1 && obstacleGrid[p][q] == -1) return 1;
        if(obstacleGrid[p][q] != -1) return obstacleGrid[p][q];

        return obstacleGrid[p][q] = help(p+1, q, obstacleGrid) + help(p, q+1, obstacleGrid);
    }
    int uniquePathsWithObstacles(vector<vector<int>>& obstacleGrid) {
        int M = obstacleGrid.size();
        int N = obstacleGrid[0].size();

        for(int i=0;i<M;i++) {
            for(int j=0;j<N;j++) {
                if(obstacleGrid[i][j] == 1) obstacleGrid[i][j] = 0;
                else obstacleGrid[i][j] = -1;
            }
        }

        return help(0, 0, obstacleGrid);
    }
};