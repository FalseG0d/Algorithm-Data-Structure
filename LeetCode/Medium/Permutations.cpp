class Solution {
public:
    vector<vector<int>> help(vector<int>& nums, int beg, int& N) {
        if(beg == N - 1) return {{nums[N - 1]}};

        vector<vector<int>> res = {};
        vector<vector<int>> smallRes = help(nums, beg + 1, N);

        for(vector<int> v : smallRes) {
            int last = v.size();
            v.push_back(nums[beg]);

            for(int i=0;i<=last;i++) {
                swap(v[i], v[last]);
                res.push_back(v);
                swap(v[last], v[i]);
            }
        }

        return res;
    }
    vector<vector<int>> permute(vector<int>& nums) {
        int N = nums.size();
        return help(nums, 0, N);
    }
};