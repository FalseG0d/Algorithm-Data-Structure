class Solution {
public:
    bool check(vector<vector<char>>& board, int p, int q){
        int N = 9;
        int check = board[p][q];
        
        for(int i=0;i<N;i++){
            if(i == p) continue;
            
            if(board[i][q] == check) return false;
        }
        
        for(int i=0;i<N;i++){
            if(i == q) continue;
            
            if(board[p][i] == check) return false;
        }
        int startI = 3 * (p / 3);
        int startJ = 3 * (q / 3);
        int endI = 3 * (p / 3 + 1);
        int endJ = 3 * (q / 3 + 1);
        
        for(int i=startI;i<endI;i++){
            for(int j=startJ;j<endJ;j++){
                if(i == p && j == q) continue;
                if(board[i][j] == check) return false;
            }
        }
        return true;
    }
    bool isValidSudoku(vector<vector<char>>& board) {
        int N = 9;
        
        for(int i=0;i<N;i++){
            for(int j=0;j<N;j++){
                if(board[i][j] == '.') continue;
                else{
                    bool flag = check(board,i,j);                  
                    if(!flag) return false;
                }
            }
        }
        
        return true;
    }
};