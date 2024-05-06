class Solution {
public:
    int jump(vector<int>& nums) {
        int N = nums.size();

        if(N == 1) return 0;
        
        int res = 0;
        int left = 0;
        int range = nums[0];

        for(int i=0;i<N;) {
            int right = range;

            while(left <= right && left < N) {
                range = max(range, left + nums[left]);
                left++;
            }

            res++;            
            i = left;
        }

        return res;
    }
};