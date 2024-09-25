class Solution {
public:
    int minFallingPathSum(vector<vector<int>>& matrix) {
        int N = matrix.size();

        for(int i=N-2;i>=0;i--) {
            for(int j=0;j<N;j++) {
                int left = INT_MAX;
                int right = INT_MAX;
                int center = INT_MAX;

                if(j > 0) left = matrix[i+1][j-1];
                if(j < N-1) right = matrix[i+1][j+1];
                center = matrix[i+1][j];

                matrix[i][j] += min(left, min(center, right));
            }
        }

        int res = INT_MAX;
        for(int i=0;i<N;i++) res = min(res, matrix[0][i]);

        return res;
    }
};  