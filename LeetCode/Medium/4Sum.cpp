class Solution {
public:
    vector<vector<int>> fourSum(vector<int>& nums, int target) {
        sort(nums.begin(),nums.end());
        
        vector<vector<int>>res;
        int N = nums.size();
        
        for(int i=0;i<N-3;i++){
            // if(i > 0 && nums[i] == nums[i-1]) continue;
            
            for(int j=i+1;j<N-2;j++){
                // if(nums[j] == nums[j-1]) continue;
                
                int left = j+1;
                int right= N-1;
                
                vector<int>temp;
                while(left < right){
                    if(nums[left] + nums[right] == target - nums[i] - nums[j]){
                        temp.push_back(nums[i]);
                        temp.push_back(nums[j]);
                        
                        temp.push_back(nums[left]);
                        temp.push_back(nums[right]);
                        
                        res.push_back(temp);
                        temp.clear();
                        
                        right--;
                        while(left < right && nums[right+1] == nums[right]) {
                            right--;
                        }
                    }
                    
                    if(nums[left] + nums[right] < target - nums[i] - nums[j]) left++;
                    else right--;
                }
                
                while(j < N - 2 && nums[j] == nums[j+1]) j++;
            }
            
            while(i < N - 1 && nums[i] == nums[i+1]) i++;
        }
        
        return res;
    }
};