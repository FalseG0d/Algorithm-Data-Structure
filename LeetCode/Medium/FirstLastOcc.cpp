class Solution {
public:
    vector<int> searchRange(vector<int>& nums, int target) {
        int N = nums.size();
        if(N == 0) return {-1, -1};

        int beg = 0;
        int end = N-1;

        vector<int> res;

        while(beg <= end) {
            int mid = beg + (end - beg) / 2;

            if(nums[mid] >= target) end = mid - 1;
            else beg = mid + 1;
        }

        res.push_back(beg >= 0 && beg < N && nums[beg] == target ? beg : -1);

        // cout<<beg<<" "<<end<<"\n";

        beg = 0;
        end = N-1;

        while(beg <= end) {
            int mid = beg + (end - beg) / 2;

            if(nums[mid] <= target) beg = mid + 1;
            else end = mid - 1;
        }

        
        // cout<<beg<<" "<<end<<"\n";

        res.push_back(end >= 0 && end < N && nums[end] == target ? end : -1);

        return res;
    }
};