class Solution {
public:
    int help(int n, int* dp) {
        if(n == 0) return 0;
        if(dp[n] != -1) return dp[n];

        int res = INT_MAX;
        
        for(int i=1;i*i<=n;i++) {
            res = min(res, help(n - i * i, dp));
        }

        return dp[n] = 1 + res;
    }
    int numSquares(int n) {
        int*dp = new int[n+1];
        
        for(int i=0;i<=n;i++) dp[i] = -1;
        dp[0] = 0;

        return help(n, dp);
    }
};