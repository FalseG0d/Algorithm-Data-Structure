class Solution {
public:
    int arrayPairSum(vector<int>& nums) {
        sort(nums.begin(), nums.end());
        int N = nums.size();
        int res = 0;

        for(int i=0;i<N;i+=2) {
            res += min(nums[i], nums[i+1]);
        }

        return res;
    }
};