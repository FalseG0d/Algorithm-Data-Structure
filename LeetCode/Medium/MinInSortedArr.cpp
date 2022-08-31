class Solution {
public:
    int findMin(vector<int>& nums) {
        int end = nums.size() - 1;
        int beg = 0;
        
        int mid = 0;
        
        while(beg < end){
            mid = (beg + end) / 2;
            
            if(mid == beg || mid == end) return nums[beg] < nums[end] ? nums[beg] : nums[end];
            
            if(nums[mid] > nums[beg] && nums[end] > nums[mid]) end = mid;
            else if(nums[mid] < nums[beg] && nums[mid] < nums[end]) end = mid;
            else beg = mid;
        }
        
        return nums[mid];
    }
};