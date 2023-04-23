class Solution {
public:
    set<vector<int>> res;

    void help(vector<int>& candidates, vector<int>temp, int pos, int target){
        int N = candidates.size();
        
        if(target == 0){
            res.insert(temp);
            return;
        }

        if(target < 0) return;
        if(pos == N) return;
        
        int offset = 1;

        while(pos + offset < N && candidates[pos] == candidates[pos + offset]) offset++;
        
        help(candidates, temp, pos + offset, target);
        temp.push_back(candidates[pos]);
        help(candidates, temp, pos + 1, target - candidates[pos]);
    }
    vector<vector<int>> combinationSum2(vector<int>& candidates, int target) {
        vector<int>temp;
        sort(candidates.begin(),candidates.end());

        help(candidates, temp, 0, target);

        vector<vector<int>>ret(res.begin(),res.end());

        return ret;
    }
};