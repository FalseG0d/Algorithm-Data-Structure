class Solution {
    int**dp;
public:
    int minDistance(string word1, string word2) {
        int M = word1.length();
        int N = word2.length();

        dp = new int*[M+1];
        for(int i=0;i<=M;i++) dp[i] = new int[N+1];

        for(int i=0;i<=M;i++) {
            for(int j=0;j<=N;j++) dp[i][j] = -1;
        }
        
        for(int i=0;i<=M;i++) dp[i][0] = i;
        for(int i=0;i<=N;i++) dp[0][i] = i;

        for(int i=1;i<=M;i++) {
            for(int j=1;j<=N;j++) {
                if(word1[i-1] == word2[j-1]) dp[i][j] = dp[i-1][j-1];
                else dp[i][j] = 1 + min(dp[i-1][j-1], min(dp[i-1][j], dp[i][j-1]));
            }
        }

        return dp[M][N];
    }
};