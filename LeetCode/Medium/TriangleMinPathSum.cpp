class Solution {
    int**dp;
public:
    int help(vector<vector<int>>& triangle, int p, int q) {
        if(q > p) return INT_MAX;
        if(p == triangle.size()) return 0;

        if(dp[p][q] != -10001) return dp[p][q];

        return dp[p][q] = triangle[p][q] + min(help(triangle, p+1, q), help(triangle, p+1, q+1));
    }
    int minimumTotal(vector<vector<int>>& triangle) {
        dp = new int*[triangle.size()];
        for(int i=0;i<triangle.size();i++) dp[i] = new int[i+1];
        
        for(int i=0;i<triangle.size();i++) {
            for(int j=0;j<=i;j++) dp[i][j] = -10001;
        }

        return help(triangle, 0, 0);
    }
};