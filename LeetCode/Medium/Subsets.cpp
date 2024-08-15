class Solution {
public:
    vector<vector<int>> help(vector<int>& nums, int curr) {
        if(curr < 0) return {{}};

        vector<vector<int>> res;
        vector<vector<int>> next = help(nums, curr-1);

        for(vector<int>tmp: next) {
            res.push_back(tmp);
            tmp.push_back(nums[curr]);
            res.push_back(tmp);
        }

        return res;
    }
    vector<vector<int>> subsets(vector<int>& nums) {
        vector<vector<int>> res;

        return help(nums, nums.size()-1);
    }
};