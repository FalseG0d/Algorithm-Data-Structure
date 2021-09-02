class Solution {
public:
    int findPeakElement(vector<int>& nums) {
        int N = nums.size();
        if(N == 1) return 0;
        
        if(nums[0] > nums[1]) return 0;
        
        for(int i=1;i<N-1;i++){
            if(nums[i] > nums[i - 1] && nums[i] > nums[i + 1]) return i;
        }
        
        if(nums[N - 1] > nums[N - 2]) return N - 1;
        
        return -1;
    }
};