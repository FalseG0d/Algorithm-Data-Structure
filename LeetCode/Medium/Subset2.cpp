class Solution {
public:
    vector<vector<int>> help(vector<int>& nums, unordered_map<int, int>& mp, int pos) {
        auto itr = mp.begin();
        for(int i=0;i<pos;i++) ++itr;

        if(itr == mp.end()) return {{}};

        vector<vector<int>> forward = help(nums, mp, pos+1);
        vector<vector<int>> res;

        int key = itr->first;
        int cnt = itr->second;

        for(vector<int> v: forward) {
            res.push_back(v);
        }

        for(vector<int> v: forward) {
            for(int i=0;i<cnt;i++) {
                v.push_back(key);
                res.push_back(v);
            }
        }

        return res;
    }
    vector<vector<int>> subsetsWithDup(vector<int>& nums) {
        unordered_map<int, int>mp;
        for(int ele : nums) mp[ele]++;

        return help(nums, mp, 0);
    }
};