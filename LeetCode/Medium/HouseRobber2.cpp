class Solution {
    int*dp;
public:
    int help(int curr, vector<int>& nums, int dir) {
        if(curr >= nums.size()) return 0;
        if(curr == nums.size() - 1 && dir == 1) {
            if(nums[0] < 1) {
                return 0;
            } else {
                return nums[curr];
            }
        }
        if(curr == 0 && dir == -1) {
            if(nums[nums.size()-1] < 1) {
                return 0;
            } else {
                return nums[curr];
            }
        }

        if(dp[curr] != -1) return dp[curr];

        nums[curr] = -nums[curr];
        int keep = help(curr + 2 * dir, nums, dir) - nums[curr];
        nums[curr] = -nums[curr];
        int leave = help(curr + 1 * dir, nums, dir);

        return dp[curr] = max(
            keep,
            leave
        );
    }
    int rob(vector<int>& nums) {
        dp = new int[nums.size()];
        for(int i=0;i<nums.size();i++) dp[i] = -1;

        int front = help(0, nums, 1);

        for(int i=0;i<nums.size();i++) dp[i] = -1;

        int back = help(nums.size()-1, nums, -1);

        return max(front, back);
    }
};