class Solution {
public:
    static bool vectorCompare(const vector<int>&v1, const vector<int>&v2) {
        return v1[0] < v2[0];
    }
    vector<vector<int>> merge(vector<vector<int>>& intervals) {
        vector<vector<int>> res;
        int N = intervals.size();

        sort(intervals.begin(), intervals.end(), vectorCompare);

        int beg = intervals[0][0];
        int end = intervals[0][1];

        for(int i=1;i<N;i++) {
            int newBeg = intervals[i][0];
            int newEnd = intervals[i][1];

            if(newBeg > end) {
                res.push_back({beg, end});

                beg = newBeg;
                end = newEnd;
            } else end = max(end, newEnd);
        }

        res.push_back({beg, end});

        return res;
    }
};