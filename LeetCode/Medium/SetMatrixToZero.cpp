class Solution {
public:
    void setZeroes(vector<vector<int>>& matrix) {
        int M = matrix.size();
        int N = matrix[0].size();
        bool*rowToZero = new bool[M]{false};
        bool*colToZero = new bool[N]{false};
        
        for(int i=0;i<M;i++){
            for(int j=0;j<N;j++){
                if(matrix[i][j] == 0) rowToZero[i] = colToZero[j] = true;
            }
        }
        
        for(int i=0;i<M;i++){
            if(rowToZero[i]){
                for(int j=0;j<N;j++) matrix[i][j] = 0;
            }
        }
        
        for(int i=0;i<N;i++){
            if(colToZero[i]){
                for(int j=0;j<M;j++) matrix[j][i] = 0;
            }
        }
    }
};