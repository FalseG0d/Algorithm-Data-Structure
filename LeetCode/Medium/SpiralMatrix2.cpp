class Solution {
public:
    vector<vector<int>> generateMatrix(int n) {
        vector<vector<int>>res(n, vector<int>(n, 0));
        
        int rowBeg = 0;
        int rowEnd = n - 1;
        int colBeg = 0;
        int colEnd = n - 1;
        int dir = 0;
        int itr = 1;
        
        while(rowBeg <= rowEnd && colBeg <= colEnd){
            if(dir == 0){
                for(int i=colBeg;i<=colEnd;i++) res[rowBeg][i] = itr++;
                
                rowBeg++;
            }
            else if(dir == 1){
                for(int i=rowBeg;i<=rowEnd;i++) res[i][colEnd] = itr++;
                
                colEnd--;
            }
            else if(dir == 2){
                for(int i=colEnd;i>=colBeg;i--) res[rowEnd][i] = itr++;
                
                rowEnd--;
            }
            else{
                for(int i=rowEnd;i>=rowBeg;i--) res[i][colBeg] = itr++;
                
                colBeg++;
            }
            
            dir = (dir + 1) % 4;
        }
        
        return res;
    }
};