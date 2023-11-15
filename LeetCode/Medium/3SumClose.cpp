class Solution {
public:
    int threeSumClosest(vector<int>& nums, int target) {
        int N = nums.size();
        int ret = nums[0] + nums[1] + nums[2];
        
        sort(nums.begin(), nums.end());

        for(int i=0;i<N;i++) {
            int to_make = target - nums[i];
            int beg = 0;
            int end = N - 1;

            while(beg < end) {
                if(beg == i) {
                    beg++;
                    continue;
                    }
                if(end == i) {
                    end--;
                    continue;
                    }

                if(abs(target - (nums[beg] + nums[end] + nums[i])) < abs(target - ret)) {
                    ret = nums[beg] + nums[end] + nums[i];
                }

                if(nums[beg] + nums[end] == to_make) break;
                else if(nums[beg] + nums[end] > to_make) end--;
                else beg++;
            }
        }

        return ret;
    }
};