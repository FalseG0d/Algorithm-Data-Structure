class Solution {
public:
    int minimumTotal(vector<vector<int>>& triangle) {
        int levels = triangle.size();
        
        for(int i=1;i<levels;i++){
            for(int j=0;j<i+1;j++){
                if(j == 0) triangle[i][j] += triangle[i-1][j];
                else if(j == triangle[i].size()-1) triangle[i][j] += triangle[i-1][j-1];
                else triangle[i][j] += min(triangle[i-1][j], triangle[i-1][j-1]);
            }
        }
        
        // for(vector<int>v:triangle){
        //     for(int i:v){
        //         cout<<i<<" ";
        //     }cout<<"\n";
        // }
        
        int res = INT_MAX;
        
        for(int x:triangle[levels-1]){
            res = min(res, x);
        }
        
        return res;
    }
};