class Solution {
public:
    int maxSubarrayLength(vector<int>& nums, int K) {
        int N = nums.size();

        int res = 1;
        unordered_map<int,int>mp;

        int beg = 0;
        int end = 0;

        while(end < N) {
            if(mp[nums[end]] < K) {
                res = max(res, end - beg + 1);
                mp[nums[end++]]++;
            } else {
                mp[nums[beg++]]--;
            }
        }

        return res;
    }
};