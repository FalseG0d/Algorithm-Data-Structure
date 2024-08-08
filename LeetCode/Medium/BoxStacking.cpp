class Solution {
public:
    int maxHeight(vector<vector<int>>& cuboids) {
        int N = cuboids.size();
        for(int i=0;i<N;i++) {
            sort(cuboids[i].begin(), cuboids[i].end());
        }

        sort(cuboids.begin(), cuboids.end());
        reverse(cuboids.begin(), cuboids.end());

        for(vector<int>cuboid: cuboids) {
            for(int ele : cuboid) cout<<ele<<" ";
            cout<<"\n";
        }

        int prev = -1;

        vector<int>dp(N, 0);
        for(int i=0;i<N;i++) dp[i] = cuboids[i][2];

        for(int i=0;i<N;i++) {
            for(int j=0;j<i;j++) {
                if(cuboids[i][1] <= cuboids[j][1] && cuboids[i][2] <= cuboids[j][2]) {
                    dp[i] = max(dp[i], dp[j] + cuboids[i][2]);
                }
            }
        }

        int maxH = 0;
        for(int ele : dp) maxH = max(maxH, ele);

        for(int ele : dp) cout<<ele<<" ";

        return maxH;
    }
};