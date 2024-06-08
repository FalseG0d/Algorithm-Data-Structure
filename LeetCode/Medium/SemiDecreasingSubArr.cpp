class Solution {
public:
    int maxSubarrayLength(vector<int>& nums) {
        int N = nums.size();
        int beg = 0;
        int res = 0;

        for(;beg<N;beg++) {
            int ele = nums[beg];
            int itr = N-1;

            while(itr > beg) {
                if(nums[itr] < ele) {
                    res = max(res, itr - beg + 1);
                    break;
                }

                itr--;
            }
        }

        return res;
    }
};