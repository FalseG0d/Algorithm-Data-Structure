class Solution {
public:
    bool searchMatrix(vector<vector<int>>& matrix, int target) {
        for(int i=0;i<matrix.size();i++){
            for(int j=0;j<matrix[i].size();j++){
                int n=matrix[i].size();
                
                if(matrix[i][j]==target){
                    return true;
                }else if(matrix[i][n-1]<target){
                    break;
                }
            }            
        }
        
        return false;
    }
};