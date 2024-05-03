class Solution {
    int res = 0;
    int*dp;
public:
    int help(int n) {
        if(n == 0) return 1;
        if(n < 0) return 0;

        if(dp[n] != -1) return dp[n];

        return dp[n] = help(n-1) + help(n-2);
    }
    int climbStairs(int n) {
        dp = new int[n+1];
        for(int i=0;i<n+1;i++) dp[i] = -1;

        return help(n);
    }
};