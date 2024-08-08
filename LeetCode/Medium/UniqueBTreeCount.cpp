class Solution {
    int*dp;
public:
    int getTreesCount(int n) {
        if(dp[n] != -1) return dp[n];
        int res = 0;

        int beg = 1;
        int end = n;

        for(int i=1;i<=n;i++) {
            int left = getTreesCount(i-1);
            int rght = getTreesCount(n-i);

            res += left * rght;
        }

        return dp[n] = res;
    }
    int numTrees(int n) {
        if(n == 0 || n == 1) return 1;

        dp = new int[n+1];

        for(int i=0;i<=n;i++) dp[i] = -1;
        dp[0] = dp[1] = 1;

        return getTreesCount(n);
    }
};