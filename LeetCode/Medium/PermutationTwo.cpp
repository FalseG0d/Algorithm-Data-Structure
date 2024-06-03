class Solution {
public:
    void help(unordered_map<int,int>& mp, vector<int> tmp, vector<vector<int>>& res) {
        bool change = true;

        for(auto itr=mp.begin();itr!=mp.end();++itr) {
            if(itr->second > 0) {
                change = false;

                tmp.push_back(itr->first);
                mp[itr->first]--;

                help(mp, tmp, res);
                
                mp[itr->first]++;
                tmp.pop_back();
            }
        }

        if(change) res.push_back(tmp);
    }
    vector<vector<int>> permuteUnique(vector<int>& nums) {
        unordered_map<int,int> mp;
        for(int ele : nums) mp[ele]++;

        vector<vector<int>> res;
        help(mp, {}, res);
        return res;
    }
};