class Solution {
public:
    int threeSumClosest(vector<int>& nums, int target) {
        int N = nums.size();
        int res = 0;
        int check = INT_MAX;

        sort(nums.begin(), nums.end());

        for(int i=0;i<N-2;i++) {
            int first = nums[i];

            int beg = i+1;
            int end = N-1;

            int tryNum = target - first;
            int tryNew = 0;

            while(beg < end) {
                tryNew = nums[beg] + nums[end];

                if(check > abs(target - (first + tryNew))) {
                    check = abs(target - (first + tryNew));
                    res = first + tryNew;
                }

                if(tryNew > tryNum) end--;
                else if(tryNew < tryNum) beg++;
                else break;
            }
        }

        return res;
    }
};