class Solution {
public:
    int nthSuperUglyNumber(int n, vector<int>& primes) {
        int N = primes.size();
        vector<int>num(N, 0);
        vector<long long>dp(n, 0);

        dp[0] = 1;

        for(int i=1;i<n;i++) {
            long long tempRes = dp[num[0]] * primes[0];
            vector<int> tempPos = {0};

            for(int j=1;j<N;j++) {
                if(dp[num[j]] * primes[j] < tempRes) {
                    tempRes = dp[num[j]] * primes[j];
                    tempPos[tempPos.size() - 1] = j;
                } else if(dp[num[j]] * primes[j] == tempRes) {
                    tempPos.push_back(j);
                }
            }

            dp[i] = tempRes;
            for(int pos : tempPos) num[pos]++;
        }

        return dp[n-1];
    }
};