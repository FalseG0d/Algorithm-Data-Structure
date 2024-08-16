class Solution {
public:
    int minPatches(vector<int>& nums, int n) {
        int itr = 0;
        long reach = 0;
        long chk = 1;
        int patch = 0;

        int len = nums.size();

        while(itr < len && reach < n) {
            if(nums[itr] <= chk) {
                reach += nums[itr];
                itr++;
            } else {
                patch++;
                reach += chk;
            }

            chk = reach+1;
        }

        while(reach < n) {
            patch++;
            reach += chk;

            chk = reach+1;
        }

        return patch;
    }
};