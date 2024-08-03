class Solution {
public:
    bool search(vector<int>& nums, int target) {
        int beg = 0;
        int end = nums.size() - 1;

        while(beg <= end) {
            int mid = beg + (end - beg) / 2;

            if(nums[mid] == target) return true;

            if(nums[mid] == nums[beg] && nums[mid] == nums[end]) {
                beg++;
                end--;

                continue;
            }

            if(nums[mid] <= nums[end]) {
                // Right Side is Sorted
                if(target >= nums[mid] && target <= nums[end]) {
                    // Target in Right Side
                    beg = mid+1;
                } else {
                    end = mid-1;
                }
            } else {
                // Left Side is Sorted
                if(target >= nums[beg] && target <= nums[mid]) {
                    // Target in Left Side
                    end = mid-1;
                } else {
                    beg = mid+1;
                }
            }
        }

        return false;
    }
};