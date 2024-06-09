class Solution {
public:
    int maximumJumps(vector<int>& nums, int target) {
        int N = nums.size();
        int*dp = new int[N];
        
        dp[N-1] = 0;

        for(int i=N-2;i>=0;i--) {
            dp[i] = -1;

            for(int j=i+1;j<N;j++) {
                if(abs(nums[i] - nums[j]) <= target)
                    dp[i] = max(dp[i], dp[j]);
            }

            if(dp[i] > -1) dp[i]++;
        }

        return dp[0];
    }
};