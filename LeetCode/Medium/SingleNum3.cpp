class Solution {
public:
    vector<int> singleNumber(vector<int>& nums) {
        if(nums.size() == 2) return nums;

        long long xorVal = 0;
        for(int ele: nums) xorVal ^= ele;

        int rightSetBits = xorVal & (~xorVal + 1);

        int xor0 = 0;
        int xor1 = 0;

        for(int ele: nums) {
            if((ele & rightSetBits) == 0) {
                xor0 ^= ele;
            } else {
                xor1 ^= ele;
            }
        }

        return {xor0, xor1};
    }
};