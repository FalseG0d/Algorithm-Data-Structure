class Solution {
public:
    int*dp;
    int help(int n) {
        if(n < 0) return 0;
        if(n == 0) return dp[n] = 1;
        if(dp[n] != -1) return dp[n];
        
        int res = 0;
        
        for(int i=0;i<n;i++){
            int left = help(i);
            int right= help(n - i - 1);
            
            res += max(1, left) * max(1, right);
        }
        
        return dp[n] = res;
    }
    
    int numTrees(int n) {
        dp = new int[n+1];
        
        for(int i=0;i<=n;i++) dp[i] = -1;
        
        help(n);
        
        return dp[n];
    }
};