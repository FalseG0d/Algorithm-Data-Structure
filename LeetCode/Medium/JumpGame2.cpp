class Solution {
public:
    int jump(vector<int>& nums) {
        int currReach = 0;
        int currMax = 0;
        int jumps = 0;
        int N = nums.size();
        
        for(int i=0;i<N-1;i++){            
            if(currMax < i + nums[i]){
                currMax = i + nums[i];
            }
            
            if(currReach == i){
                jumps++;
                currReach = currMax;
            }
        }
        
        return jumps;
    }
};