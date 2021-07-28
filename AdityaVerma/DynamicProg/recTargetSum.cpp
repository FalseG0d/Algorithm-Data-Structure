class Solution {
public:
    int help(vector<int>& nums,int curr,int target,int n){
        if(n==0) return curr==target?1:0;
        
        return help(nums,curr+nums[n-1],target,n-1)+help(nums,curr-nums[n-1],target,n-1);
    }
    int findTargetSumWays(vector<int>& nums, int target) {
        return help(nums,0,target,nums.size());
    }
};