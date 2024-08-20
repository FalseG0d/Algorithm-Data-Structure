class Solution {
public:
    int removeDuplicates(vector<int>& nums) {
        int N = nums.size();

        int curr = 0;
        int prev = -101;

        int res = 0;

        while(curr < N) {
            if(nums[curr] != prev) {
                res++;
                prev = nums[curr];
            } else {
                nums[curr] = 101;
            }

            curr++;
        }

        sort(nums.begin(), nums.end());

        return res;
    }
};