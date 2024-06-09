class Solution {
public:
    int arithmeticTriplets(vector<int>& nums, int diff) {
        int res = 0;
        int N = nums.size();

        for(int i=0;i<N-2;i++) {
            for(int j=i+1;j<N-1;j++) {
                if(nums[j] - nums[i] < diff) continue;
                else if(nums[j] - nums[i] > diff) break;
                else {
                    for(int k=j+1;k<N;k++) {
                        if(nums[k] - nums[j] < diff) continue;
                        else if(nums[k] - nums[j] == diff) res++;
                        else break;
                    }
                }
            }
        }

        return res;
    }
};