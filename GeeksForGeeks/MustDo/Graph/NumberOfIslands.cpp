// { Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

 // } Driver Code Ends
class Solution {
  public:
    void dfs(vector<vector<char>>& grid,int x,int y){
        int M = grid.size();
        int N = grid[0].size();
        
        if(x < 0 || x >= M) return;
        if(y < 0 || y >= N) return;
        
        if(grid[x][y] == '0' || grid[x][y] == '2') return;
        
        grid[x][y] = '2';
        
        dfs(grid,x + 1, y);
        dfs(grid,x - 1, y);
        
        dfs(grid,x, y + 1);
        dfs(grid,x, y - 1);
        
        dfs(grid,x - 1, y - 1);
        dfs(grid,x - 1, y + 1);
        dfs(grid,x + 1, y - 1);
        dfs(grid,x + 1, y + 1);
    }
    // Function to find the number of islands.
    int numIslands(vector<vector<char>>& grid) {
        // Code here
        int M = grid.size();
        int N = grid[0].size();
        
        int res = 0;
        
        for(int i=0;i<M;i++){
            for(int j=0;j<N;j++){
                if(grid[i][j] == '0' || grid[i][j] == '2') continue;
                else{
                    res++;
                    dfs(grid,i,j);
                }
            }
        }
        
        return res;
    }
};

// { Driver Code Starts.
int main() {
    int tc;
    cin >> tc;
    while (tc--) {
        int n, m;
        cin >> n >> m;
        vector<vector<char>> grid(n, vector<char>(m, '#'));
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < m; j++) {
                cin >> grid[i][j];
            }
        }
        Solution obj;
        int ans = obj.numIslands(grid);
        cout << ans << '\n';
    }
    return 0;
}  // } Driver Code Ends