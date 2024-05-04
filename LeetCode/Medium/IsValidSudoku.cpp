class Solution {
public:
    bool isDigit(char ch) {
        return ch <= '9' && ch >= '0';
    }
    bool isValidSudoku(vector<vector<char>>& board) {
        vector<vector<int>>rows(9, vector<int>(9));
        vector<vector<int>>cols(9, vector<int>(9));
        vector<vector<int>>grid(9, vector<int>(9));

        for(int i=0;i<9;i++) {
            for(int j=0;j<9;j++) rows[i][j] = cols[i][j] = grid[i][j] = 0;
        }

        for(int i=0;i<9;i++) {
            for(int j=0;j<9;j++) {
                if(isDigit(board[i][j])) {
                    rows[i][board[i][j] - '1']++;
                    cols[j][board[i][j] - '1']++;
                    grid[3 * (i / 3) + j / 3][board[i][j] - '1']++;

                    if(
                        rows[i][board[i][j] - '1'] > 1 ||
                        cols[j][board[i][j] - '1'] > 1 ||
                        grid[3 * (i / 3) + j / 3][board[i][j] - '1'] > 1
                    ) return false;
                }
            }
        }

        return true;
    }
};