class Solution {
public:
    int numIdenticalPairs(vector<int>& nums) {
        int N = nums.size();
        int res = 0;

        for(int i=0;i<N-1;i++) {
            for(int j=i+1;j<N;j++) {
                if(nums[i] == nums[j]) res++;
            }
        }

        return res;
    }
};