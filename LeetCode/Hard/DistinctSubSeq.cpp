class Solution {
    int**dp;
public:
    int help(string& s, string& t, int itr1, int itr2) {
        if(itr2 == t.length()) return 1;
        if(itr1 == s.length()) return 0;

        if(dp[itr1][itr2] != -1) return dp[itr1][itr2];

        if(s[itr1] == t[itr2]) return dp[itr1][itr2] = help(s, t, itr1+1, itr2+1) + help(s, t, itr1+1, itr2);
        else return dp[itr1][itr2] = help(s, t, itr1+1, itr2);
    }
    int numDistinct(string s, string t) {
        int M = s.length();
        int N = t.length();

        if(N > M) return 0;

        dp = new int*[M+1];
        for(int i=0;i<=M;i++) dp[i] = new int[N+1];

        for(int i=0;i<=M;i++) {
            for(int j=0;j<=N;j++) {
                if(i == 0 || j == 0) {
                    dp[i][j] = 0;
                    continue;
                } else {
                    if(s[i-1] == t[j-1]) dp[i][j] = 1 + dp[i-1][j-1];
                    else dp[i][j] = max(dp[i-1][j], dp[i][j-1]);
                }
            }
        }
        
        if(dp[M][N] < t.length()) return 0;

        for(int i=0;i<=M;i++) {
            for(int j=0;j<=N;j++) dp[i][j] = -1;
        }

        return help(s, t, 0, 0);
    }
};