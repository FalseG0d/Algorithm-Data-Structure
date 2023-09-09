class Solution {
public:
    vector<vector<int>> insert(vector<vector<int>>& intervals, vector<int>& newInterval) {
        vector<vector<int>> res;
        int N = intervals.size();
        
        int i = 0;

        while(i < N && intervals[i][1] < newInterval[0]) res.push_back(intervals[i++]);
        
        vector<int> mergedInterval = newInterval;
        
        while(i < N && intervals[i][0] <= newInterval[1]){
            mergedInterval[0] = min(mergedInterval[0], intervals[i][0]);
            mergedInterval[1] = max(mergedInterval[1], intervals[i++][1]);
        }
        res.push_back(mergedInterval);
        
        while(i < N) res.push_back(intervals[i++]);
        
        return res;
    }
};