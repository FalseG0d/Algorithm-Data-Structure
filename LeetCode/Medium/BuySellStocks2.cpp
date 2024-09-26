class Solution {
    int**dp;
public:
    int maxProfit(vector<int>& prices) {
        int N = prices.size();
        dp = new int*[N];
        for(int i=0;i<N;i++) dp[i] = new int[2];

        dp[N-1][0] = prices[N-1]; // Last time to Sell
        dp[N-1][1] = 0; // No Point Buying

        for(int i=N-2;i>=0;i--) {
            dp[i][0] = max(dp[i+1][0], prices[i] + dp[i+1][1]); // Sell
            dp[i][1] = max(dp[i+1][1], -prices[i] + dp[i+1][0]); // Buy
        }

        return dp[0][1];
    }
};