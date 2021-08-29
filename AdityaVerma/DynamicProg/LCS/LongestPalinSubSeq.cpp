class Solution {
public:
    int longestPalindromeSubseq(string str) {
        int N = str.length();
        
        int**dp = new int*[N+1];
        for(int i=0;i<N+1;i++) dp[i] = new int[N+1];
        
        for(int i=0;i<N+1;i++) dp[i][0] = dp[0][i] = 0;
        
        for(int i=1;i<N+1;i++){
            for(int j=1;j<N+1;j++){
                if(str[i - 1] == str[N - j]) dp[i][j] = dp[i-1][j-1] + 1;
                else dp[i][j] = max(dp[i-1][j],dp[i][j-1]);
            }
        }
        
        return dp[N][N];
    }
};