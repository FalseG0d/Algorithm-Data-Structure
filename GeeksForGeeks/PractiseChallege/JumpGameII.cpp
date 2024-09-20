class Solution {
public:
    int jump(vector<int>& nums) {
        int N = nums.size();
        
        if(N == 1) return 0;

        int left = 0;
        int range = nums[0];

        if(range >= N-1) return 1;

        int jmp = 1;

        for(int i=0;i<N;i++) {
            int right = min(N-1, range);

            while(left <= right) {
                range = min(N-1, max(range, left+nums[left]));
                left++;
            }

            jmp++;
            if(range == N-1) break;
        }

        return jmp;
    }
};