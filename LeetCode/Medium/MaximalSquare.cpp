class Solution {
public:
    int max(int a, int b){
        return a > b ? a : b;
    }
    int min(int a, int b, int c){
        int res = INT_MAX;
        
        if(a < b){
            res = a < c ? a : c;
        }else{
            res = b < c ? b : c;
        }
        
        return res;
    }
    int maximalSquare(vector<vector<char>>& matrix) {
        int M = matrix.size();
        int N = matrix[0].size();
        
        vector<vector<int>>mat(M, vector<int>(N, 0));
        
        int res = 0;
        
        for(int i=0;i<M;i++){
            for(int j=0;j<N;j++){
                if(matrix[i][j] == '1'){
                    res = 1;
                    mat[i][j] = 1;
                }else{
                    mat[i][j] = 0;
                }
            }
        }
        
        for(int i=1;i<M;i++){
            for(int j=1;j<N;j++){
                if(mat[i][j] == 0) continue;
                else{
                    res = max(res, 1);
                    
                    int minAdj = INT_MAX;

                    minAdj = min(mat[i][j-1], mat[i-1][j], mat[i-1][j-1]);

                    if(minAdj > 0) mat[i][j] = minAdj + 1;

                    res = max(res, mat[i][j]);
                }
            }
        }
        
        return res * res;
        }
    };