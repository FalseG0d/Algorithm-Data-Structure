class Solution {
public:
    void setZeroes(vector<vector<int>>& matrix) {
        int M = matrix.size();
        int N = matrix[0].size();

        vector<bool>rowZero(M, false);
        vector<bool>colZero(N, false);

        for(int i=0;i<M;i++) {
            for(int j=0;j<N;j++) {
                if(matrix[i][j] == 0) {
                    colZero[j] = rowZero[i] = true;
                }
            }
        }

        for(int i=0;i<M;i++) {
            if(rowZero[i]) {
                for(int j=0;j<N;j++) matrix[i][j] = 0;
            }
        }

        for(int i=0;i<N;i++) {
            if(colZero[i]) {
                for(int j=0;j<M;j++) matrix[j][i] = 0;
            }
        }
    }
};