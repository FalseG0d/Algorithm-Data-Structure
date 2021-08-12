class Solution {
public:
    bool canJump(vector<int>& nums) {
        int N=nums.size();
        int reachable=0;
        
        for(int i=0;i<N;i++){
            if(reachable < i) return false;
            
            reachable=max(reachable, nums[i]+i);
        }
        
        return true;
    }
};