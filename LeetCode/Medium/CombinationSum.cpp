class Solution {
public:
    vector<vector<int>>res;
    
    void help(vector<int>& candidates, vector<int>temp, int cur, int target){
        int N = candidates.size();
        
        if(cur == N) return;
        if(target < 0) return;
        
        if(target == 0){
            res.push_back(temp);
            return;
        }
        
        help(candidates, temp, cur + 1, target);
        temp.push_back(candidates[cur]);
        help(candidates, temp, cur, target - candidates[cur]);
    }
    
    vector<vector<int>> combinationSum(vector<int>& candidates, int target) {
        vector<int>temp;
        help(candidates, temp, 0, target);
        
        return res;
    }
};