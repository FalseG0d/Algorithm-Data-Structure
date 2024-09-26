class Solution {
    int***dp;
public:
    int maxProfit(vector<int>& prices) {
        int N = prices.size();
        dp = new int**[N+1];
        for(int i=0;i<N+1;i++) dp[i] = new int*[2];
        
        for(int i=0;i<N+1;i++) {
            for(int j=0;j<2;j++) dp[i][j] = new int[3];
        }

        for(int i=0;i<N+1;i++) {
            for(int j=0;j<2;j++) {
                for(int k=0;k<3;k++) {
                    if(k == 0 || i == N) dp[i][j][k] = 0;
                }
            }
        }

        int**prev = new int*[2];
        prev[0] = new int[3];
        prev[1] = new int[3];

        for(int i=0;i<2;i++) {
            for(int j=0;j<3;j++) prev[i][j] = 0;
        }
        
        int**curr = NULL;

        for(int i=N-1;i>=0;i--) {
            curr = new int*[2];
            curr[0] = new int[3];
            curr[1] = new int[3];

            // Sell
            curr[0][0] = 0;
            curr[0][1] = max(prices[i] + prev[1][0], prev[0][1]);
            curr[0][2] = max(prices[i] + prev[1][1], prev[0][2]);

            // Buy
            curr[1][0] = 0;
            curr[1][1] = max(-prices[i] + prev[0][1], prev[1][1]);
            curr[1][2] = max(-prices[i] + prev[0][2], prev[1][2]);

            prev = curr;
        }
        
        return curr[1][2];
    }
};