class Solution {
public:
    int singleNonDuplicate(vector<int>& nums) {
        int N = nums.size();
        
        if(N == 1) return nums[0];
        
        int beg = 0;
        int end = N - 1;

        while(beg < end) {
            int mid = beg + (end - beg) / 2;

            if(nums[mid] == nums[mid - 1]) {
                if(mid % 2 == 0) end = mid;
                else beg = mid + 1;
            }else if(nums[mid] == nums[mid + 1]) {
                if(mid % 2 == 0) beg = mid;
                else end = mid - 1;
            }else {
                return nums[mid];
            }
        }

        return nums[beg];
    }
};