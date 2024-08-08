class Solution {
public:
    bool searchMatrix(vector<vector<int>>& matrix, int target) {
        int M = matrix.size();
        int N = matrix[0].size();

        int i=0;
        int j=N-1;

        while(i < M && j >= 0) {
            if(matrix[i][j] < target) i++;
            else if(matrix[i][j] > target) j--;
            else return true;
        }

        return false;
    }
};