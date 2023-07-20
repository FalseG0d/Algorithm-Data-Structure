class Solution {
public:
    int largestSumAfterKNegations(vector<int>& nums, int k) {
        sort(nums.begin(),nums.end());
        int i = 0;

        while(i<nums.size() && nums[i]<0 && k>0)
        {
            nums[i] *= -1;
            i++;
            k--;
        }
        
        if(k%2 == 1)
        {
            sort(nums.begin(),nums.end());
            nums[0] *= -1;
        }
        int sum = 0;
        for(int n : nums)
        {
            sum += n;
        }
        return sum;
    }
};