class Solution {
public:
    vector<int> spiralOrder(vector<vector<int>>& matrix) {
        int M = matrix.size();
        int N = matrix[0].size();
        vector<int> res(M*N);
        int itr = 0;

        int rowBeg = 0;
        int rowEnd = M-1;

        int colBeg = 0;
        int colEnd = N-1;

        while(rowBeg <= rowEnd && colBeg <= colEnd) {
            for(int i=colBeg;i<=colEnd;i++) res[itr++] = matrix[rowBeg][i];
            rowBeg++;
            if(rowBeg > rowEnd) break;
            
            for(int i=rowBeg;i<=rowEnd;i++) res[itr++] = matrix[i][colEnd];
            colEnd--;
            if(colBeg > colEnd) break;
            
            for(int i=colEnd;i>=colBeg;i--) res[itr++] = matrix[rowEnd][i];
            rowEnd--;
            if(rowBeg > rowEnd) break;
            
            for(int i=rowEnd;i>=rowBeg;i--) res[itr++] = matrix[i][colBeg];
            colBeg++;
            if(colBeg > colEnd) break;
        }

        return res;
    }
};