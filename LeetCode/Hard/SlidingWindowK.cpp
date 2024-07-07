class Solution {
public:
    vector<int> maxSlidingWindow(vector<int>& nums, int K) {
        if(K == 1) return nums;

        int N = nums.size();
        deque<int>deq;
        vector<int> res(N-K+1);

        for(int i=0;i<K;i++) {
            while(!deq.empty() && deq.back() < nums[i]) deq.pop_back();

            deq.push_back(nums[i]);
        }

        for(int i=0;i<=N-K;i++) {
            res[i] = deq.front();

            if(deq.front() == nums[i]) deq.pop_front();

            while(!deq.empty() && i+K < N && deq.back() < nums[i+K]) deq.pop_back();

            if(i+K < N) deq.push_back(nums[i+K]);
        }

        return res;
    }
};