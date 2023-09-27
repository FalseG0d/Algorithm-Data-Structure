class Solution {
public:
    int M = 0;
    int N = 0;
    bool** visited;
    
    bool help(int i, int j, int curr, string &word, vector<vector<char>>& board) {
        if(curr == word.length()) return true;
        if(i >= M || j >= N || i < 0 || j < 0) return false;
        
        if(visited[i][j]) return false;
        if(word[curr] != board[i][j]) return false;
        
        visited[i][j] = true;
        
        // cout<<word[curr]<<" "<<i<<" "<<j<<"\n";
        
        bool up     = help(i - 1, j, curr + 1, word, board);
        bool down   = help(i + 1, j, curr + 1, word, board);
        bool left   = help(i, j - 1, curr + 1, word, board);
        bool right  = help(i, j + 1, curr + 1, word, board);
        
        visited[i][j] = false;
        
        return up || down || left || right;
    }
    bool exist(vector<vector<char>>& board, string word) {
        M = board.size();
        N = board[0].size();
        
        visited = new bool*[M];
        
        for(int i=0;i<M;i++) visited[i] = new bool[N]{false};
        
        bool res = false;
        
        for(int i=0;i<M;i++){
            for(int j=0;j<N;j++){
                if(res) return true;
                
                res = help(i, j, 0, word, board);
            }
        }
        
        return res;
    }
};