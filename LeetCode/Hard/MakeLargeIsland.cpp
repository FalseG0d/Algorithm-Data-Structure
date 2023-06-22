class Solution {
public:
    map<int,int>mp;
    int areaDFS(vector<vector<int>>& grid, int i, int j, int M, int N, int id){
        if(i < 0 || j < 0 || i == M || j == N) return 0;
        if(grid[i][j] != 1) return 0;
        
        grid[i][j] = id;
        int res = 1 + areaDFS(grid,i-1,j,M,N,id) + areaDFS(grid,i+1,j,M,N,id) + areaDFS(grid,i,j-1,M,N,id) + areaDFS(grid,i,j+1,M,N,id);
        
        return res;
    }
    
    int val(int i, int j, vector<vector<int>>& grid, int M, int N){
        if(i < 0 || i == M || j < 0 || j == N) return 0;
        else return grid[i][j];
    }
    
    int largestIsland(vector<vector<int>>& grid) {
        int M = grid.size();
        int N = grid[0].size();
        
        int res = 0;
        int id = 2;
        
        mp[0] = 0;
        
        for(int i=0;i<M;i++){
            for(int j=0;j<N;j++){
                if(grid[i][j] == 1){
                    int count = areaDFS(grid,i,j,M,N,id);
                    
                    mp[id] = count;
                    res = max(res, count);
                    
                    id++;
                }
            }
        }
        
        for(int i=0;i<M;i++){
            for(int j=0;j<N;j++){
                if(grid[i][j] == 0){
                    int temp = 1;
                    set<int>s;
                    
                    s.insert(val(i+1,j,grid,M,N));
                    s.insert(val(i-1,j,grid,M,N));
                    
                    s.insert(val(i,j+1,grid,M,N));
                    s.insert(val(i,j-1,grid,M,N));
                    
                    for(int ele:s){
                        temp += mp[ele];
                    }
                    
                    res = max(res, temp);
                    
                    // cout<<i<<","<<j<<":"<<res<<"\n";
                }
            }
        }
        
        return res;
    }
};