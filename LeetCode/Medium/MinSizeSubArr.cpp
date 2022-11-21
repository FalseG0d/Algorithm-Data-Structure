class Solution {
public:
    int minSubArrayLen(int target, vector<int>& nums) {
        int beg = 0;
        int end = 0;
        
        int N = nums.size();
        
        int sum = 0;
        int res = INT_MAX;
        
        while(end <= N){
            while(sum >= target) {
                res = min(res, end - beg);
                sum -= nums[beg++];
            }
            
            if(end < N) sum += nums[end];
            end++;
        }
        
        return res == INT_MAX ? 0 : res;
    }
};