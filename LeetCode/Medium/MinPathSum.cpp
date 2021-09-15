class Solution {
public:
    int minPathSum(vector<vector<int>>& grid) {
        int M = grid.size();
        int N = grid[0].size();
        
        grid.push_back(vector<int>(N+1,1000));
        for(int i=0;i<M;i++) grid[i].push_back(1000);
        
        // for(vector v : grid){
        //     for(int ele : v) cout<<ele<<" ";
        //     cout<<"\n";
        // }
        
        for(int i=M-1;i>=0;i--){
            for(int j=N-1;j>=0;j--){
                if(i == M - 1 && j == N - 1) continue;
                
                grid[i][j] += min(grid[i+1][j], grid[i][j+1]);
            }
        }
        
        return grid[0][0];
    }
};