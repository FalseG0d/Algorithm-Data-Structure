class Solution {
public:
    vector<vector<int>> res;
    
    void help(int beg, int end, vector<int>& nums, vector<int>temp) {
        if(beg > end){
            res.push_back(temp);
            return;
        }
        
        help(beg + 1, end, nums, temp);
        temp.push_back(nums[beg]);
        help(beg + 1, end, nums, temp);
    }
    
    vector<vector<int>> subsets(vector<int>& nums) {
        int end = nums.size();
        int beg = 0;
        
        help(0, end - 1, nums, {});
        
        return res;
    }
};