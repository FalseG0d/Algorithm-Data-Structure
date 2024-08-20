class Solution {
public:
    void moveZeroes(vector<int>& nums) {
        int N = nums.size();

        int itr1 = 0;
        int itr2 = 0;

        while(itr2 < N) {
            if(nums[itr2] != 0) {
                nums[itr1++] = nums[itr2];
            }

            itr2++;
        }

        while(itr1 < N) {
            nums[itr1++] = 0;
        }
    }
};