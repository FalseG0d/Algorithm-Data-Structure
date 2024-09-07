class Solution {
public:
    void help(int k, int n, int curr, vector<int>tmp, vector<vector<int>>& res) {
        if(n == 0 && k == 0) {
            res.push_back(tmp);
            return;
        }
        if(n < 0 || k == 0 || curr > 9) return;

        help(k, n, curr+1, tmp, res);
        tmp.push_back(curr);
        help(k-1, n-curr, curr+1, tmp, res);
    }
    vector<vector<int>> combinationSum3(int k, int n) {
        int maxSum = 0;
        for(int i=9;i>9-k;i--) maxSum += i;

        if(n > maxSum) return {};

        vector<vector<int>>res;

        help(k, n, 1, {}, res);

        return res;
    }
};