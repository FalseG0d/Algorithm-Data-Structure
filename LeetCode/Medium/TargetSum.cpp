class Solution {
    int**dp;
public:
    int help(vector<int>& nums, int target, int itr) {
        if(itr == nums.size()) {
            return target == 0 ? 1 : 0;
        }

        if(target < 0) return 0;

        if(dp[itr][target] != -1) return dp[itr][target];

        return dp[itr][target] = help(nums, target - nums[itr], itr+1) + help(nums, target, itr+1);
    }
    int findTargetSumWays(vector<int>& nums, int target) {
        if(target < 0) target = -target;
        
        int sum = 0;
        int N = nums.size();

        for(int ele : nums) sum += ele;
        int targetSum = (sum + target);

        if(targetSum % 2 != 0) return 0;

        targetSum /= 2;

        dp = new int*[N + 1];

        for(int i=0;i<N+1;i++) dp[i] = new int[targetSum + 1];

        for(int i=0;i<N+1;i++) {
            for(int j=0;j<targetSum+1;j++) dp[i][j] = -1;
        }

        return help(nums, targetSum, 0);
    }
};