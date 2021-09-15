class Solution {
public:
    vector<int> spiralOrder(vector<vector<int>>& matrix) {
        vector<int>res;
        
        int M = matrix.size();
        int N = matrix[0].size();
        
        int rowBeg = 0;
        int rowEnd = M - 1;
        
        int colBeg = 0;
        int colEnd = N - 1;
        
        int dir = 0;
        
        while(res.size() < M * N){
            if(dir == 0){
                for(int i=colBeg;i<=colEnd;i++) res.push_back(matrix[rowBeg][i]);
                
                rowBeg++;
            }else if(dir == 1){
                for(int i=rowBeg;i<=rowEnd;i++) res.push_back(matrix[i][colEnd]);
                
                colEnd--;
            }else if(dir == 2){
                for(int i=colEnd;i>=colBeg;i--) res.push_back(matrix[rowEnd][i]);
                
                rowEnd--;
            }else{
                for(int i=rowEnd;i>=rowBeg;i--) res.push_back(matrix[i][colBeg]);
                
                colBeg++;
            }
            
            dir = (dir + 1) % 4;
        }
        
        return res;
    }
};