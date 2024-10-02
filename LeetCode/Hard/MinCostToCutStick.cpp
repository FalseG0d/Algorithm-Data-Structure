//  0
//  0   0
//  3   0   0
//  0   3   0   0
//  0   0   2   0   0
//  0   0   0   3   0   0


class Solution {
public:
    int minCost(int n, vector<int>& v) {
        vector<int>cuts;

        sort(v.begin(), v.end());

        cuts.push_back(0);
        for(int ele: v) cuts.push_back(ele);
        cuts.push_back(n);

        int N = cuts.size();

        int**dp = new int*[N];
        for(int i=0;i<N;i++) dp[i] = new int[i+1];

        for(int i=0;i<N;i++) dp[i][i] = 0;
        for(int i=1;i<N;i++) dp[i][i-1] = 0;
        
        for(int i=2;i<N;i++) {
            for(int j=0;i+j<N;j++) {
                dp[i+j][j] = INT_MAX;

                for(int k=j+1;k<i+j;k++) {
                    dp[i+j][j] = min(dp[i+j][j], cuts[i+j] - cuts[j] + dp[k][j] + dp[i+j][k]);
                }
            }
        }

        return dp[N-1][0];
    }
};