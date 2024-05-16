class Solution {
public:
    int maxProfit(vector<int>& prices) {
        int N = prices.size();
        int ans = 0;

        int beg = 0;
        int end = 0;

        while(end < N) {
            ans = max(ans, prices[end] - prices[beg]);
            if(prices[end] < prices[beg]) beg = end;

            end++;
        }

        return ans;
    }
};