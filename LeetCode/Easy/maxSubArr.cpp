class Solution {
public:
    int maxSubArray(vector<int>& nums) {
        if(nums.size()==0)return 0;
        if(nums.size()==1)return nums[0];
        
        int max_sum=nums[0];
        int tem_sum=0;
        
        for(int i=0;i<nums.size();i++){
            tem_sum+=nums[i];
            
            if(tem_sum>max_sum)max_sum=tem_sum;
            
            if(tem_sum<0)tem_sum=0;
        }
        
        return max_sum;
        
    }
};