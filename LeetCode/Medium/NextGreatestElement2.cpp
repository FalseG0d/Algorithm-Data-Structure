class Solution {
public:
    vector<int> nextGreaterElements(vector<int>& nums) {
        stack<int>st;
        int N = nums.size();
        vector<int> res(N);

        for(int i=2*N-1;i>=0;i--) {
            int ele = nums[i%N];

            while(!st.empty() && st.top() <= ele) st.pop();

            if(i < N) {
                if(st.empty()) res[i] = -1;
                else res[i] = st.top();
            }

            st.push(ele);
        }

        return res;
    }
};