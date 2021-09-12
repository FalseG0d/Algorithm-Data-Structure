class Solution {
public:
    vector<int> searchRange(vector<int>& nums, int target) {
        int beg = 0;
        int end = nums.size() - 1;
        
        int res = -1;
        
        vector<int>ret;
        
        while(beg <= end){
            int mid = (beg + end) / 2;
            
            if(nums[mid] == target){
                res = mid;
                end = mid - 1;
                continue;
            }
            
            if(nums[mid] > target) end = mid - 1;
            else beg = mid + 1;
        }
        
        ret.push_back(res);
        
        res = -1;
        
        beg = 0;
        end = nums.size() - 1;
        
        while(beg <= end){
            int mid = (beg + end) / 2;
            
            if(nums[mid] == target){
                res = mid;
                beg = mid + 1;
                continue;
            }
            
            if(nums[mid] > target) end = mid - 1;
            else beg = mid + 1;
        }
        
        ret.push_back(res);
        
        return ret;
    }
};