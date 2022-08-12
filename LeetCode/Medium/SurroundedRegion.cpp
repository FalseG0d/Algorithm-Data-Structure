class Solution {
public:

    void dfs(vector<vector<char>>& board, int p, int q) {
        int M = board.size();
        int N = board[0].size();
        
        if(p < 0 || p >= M || q < 0 || q >= N) return;
        if(board[p][q] == 'X' || board[p][q] == '1') return;
        
        board[p][q] = '1';
        dfs(board, p-1,q);
        dfs(board, p+1,q);
        dfs(board, p,q-1);
        dfs(board, p,q+1);
    }
    
    void solve(vector<vector<char>>& board) {
        int M = board.size();
        int N = board[0].size();
        
        for(int i=0;i<N;i++){
            if(board[0][i] == 'O') dfs(board, 0, i);
            if(board[M-1][i] == 'O') dfs(board, M-1, i);
        }
        for(int i=0;i<M;i++){
            if(board[i][0] == 'O') dfs(board, i, 0);
            if(board[i][N-1] == 'O') dfs(board, i, N-1);
        }      
        for(int i=0;i<M;i++){
            for(int j=0;j<N;j++){
                if(board[i][j] == 'O') board[i][j] = 'X';
                else if(board[i][j] == '1') board[i][j] = 'O';
            }
        }
    }
};