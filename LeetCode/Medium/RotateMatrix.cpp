class Solution {
public:
    void rotate(vector<vector<int>>& matrix) {
        int N = matrix.size();
        int**mat = new int*[N];

        for(int i=0;i<N;i++) mat[i] = new int[N];
        
        for(int i=0;i<N;i++){
            for(int j=0;j<N;j++) mat[j][i] = matrix[i][j];
        }
        
        for(int i=0;i<N;i++){
            for(int j=0;j<N/2;j++) swap(mat[i][j], mat[i][N - j - 1]);
        }
        
        for(int i=0;i<N;i++){
            for(int j=0;j<N;j++) matrix[i][j] = mat[i][j];
        }
    }
};