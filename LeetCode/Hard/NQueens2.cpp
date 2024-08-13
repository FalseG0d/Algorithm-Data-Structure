class Solution {
public:
    bool check(int p, int q, int& N, vector<vector<bool>>& board) {
        int cnt = 0;

        for(int i=0;i<N;i++) {
            if(board[p][i]) cnt++;
        }

        if(cnt > 1) return false;

        cnt = 0;

        for(int i=0;i<N;i++) {
            if(board[i][q]) cnt++;
        }

        if(cnt > 1) return false;

        cnt = 0;
        int itr1 = p;
        int itr2 = q;

        while(itr1 > 0 && itr2 > 0) {
            if(board[--itr1][--itr2]) cnt++;
        }
        
        itr1 = p;
        itr2 = q;

        while(itr1 < N-1 && itr2 < N-1) {
            if(board[++itr1][++itr2]) cnt++;
        }
        
        itr1 = p;
        itr2 = q;

        while(itr1 < N-1 && itr2 > 0) {
            if(board[++itr1][--itr2]) cnt++;
        }
        
        itr1 = p;
        itr2 = q;

        while(itr1 > 0 && itr2 < N-1) {
            if(board[--itr1][++itr2]) cnt++;
        }

        if(cnt > 0) return false;

        return true;
    }
    int nQueens(int itr, int& N, vector<vector<bool>>& board) {
        if(itr == N) return 1;

        int res = 0;

        for(int i=0;i<N;i++) {
            board[itr][i] = true;
            if(check(itr, i, N, board)) {
                res += nQueens(itr+1, N, board);
            }
            board[itr][i] = false;
        }

        return res;
    }
    int totalNQueens(int n) {
        vector<vector<bool>>board(n, vector<bool>(n));

        return nQueens(0, n, board);
    }
};