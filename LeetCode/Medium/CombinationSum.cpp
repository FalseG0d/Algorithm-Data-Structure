class Solution {
public:
    void solve(vector<int>& candidates, vector<vector<int>>& res, int target, int pos, vector<int> curr) {
        if(pos == candidates.size()) return;
        
        if(target == candidates[pos]) {
            curr.push_back(candidates[pos]);
            res.push_back(curr);

            return;
        }
        
        if(target < 0) return;

        // Leave Current
        solve(candidates, res, target, pos+1, curr);
        // Keep Current & Stay Here
        curr.push_back(candidates[pos]);
        solve(candidates, res, target - candidates[pos], pos, curr);
    }
    vector<vector<int>> combinationSum(vector<int>& candidates, int target) {
        vector<vector<int>>res;
        sort(candidates.begin(), candidates.end());

        solve(candidates, res, target, 0, {});

        return res;
    }
};