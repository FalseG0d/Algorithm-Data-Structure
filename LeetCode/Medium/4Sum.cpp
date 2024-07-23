class Solution {
public:
    vector<vector<int>> fourSum(vector<int>& nums, int sum) {
        int N = nums.size();
        sort(nums.begin(), nums.end());
        vector<vector<int>> res;

        for(int i=0;i<N-3;i++) {
            if(i > 0 && nums[i] == nums[i-1]) continue;

            for(int j=i+1;j<N-2;j++) {
                if(j > i+1 && nums[j] == nums[j-1]) continue;

                long long target = (long long)sum - ((long long)nums[i] + (long long)nums[j]);

                int beg = j+1;
                int end = N-1;

                while(beg < end) {
                    int tmp = nums[beg] + nums[end];

                    if(tmp == target) {
                        res.push_back({nums[i], nums[j], nums[beg], nums[end]});
                        beg++;
                        while(beg < N && nums[beg] == nums[beg-1]) beg++;
                        end--;
                        while(end >= 0 && nums[end] == nums[end+1]) end--;
                    } else if(tmp < target) {
                        beg++;
                    } else {
                        end--;
                    }
                }
            }
        }
        
        return res;
    }
};