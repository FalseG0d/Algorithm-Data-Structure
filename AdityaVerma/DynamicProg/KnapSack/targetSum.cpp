class Solution {
public:
    int help(vector<int>& nums,int target,int n){
        if(n==0) return target==0?1:0;
        
        return help(nums,target+nums[n-1],n-1)+help(nums,target-nums[n-1],n-1);
    }
    int findTargetSumWays(vector<int>& nums, int target) {        
        return help(nums,target,nums.size());
    }
};