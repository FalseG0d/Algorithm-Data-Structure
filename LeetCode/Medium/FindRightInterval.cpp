class Solution {
public:
    static bool compare(vector<int>& v1, vector<int>& v2) {
        return v1[0] < v2[0];
    }

    vector<int> findRightInterval(vector<vector<int>>& intervals) {
        int N = intervals.size();
        vector<int> res(N, -1);

        for(int i=0;i<N;i++) {
            intervals[i].push_back(i);
        }

        sort(intervals.begin(), intervals.end(), compare);

        for(int i=0;i<N;i++) {
            int end = intervals[i][1];
            int idx = -1;

            int min = 0;
            int max = N-1;

            while(min <= max) {
                int mid = min + (max - min) / 2;

                if(intervals[mid][0] >= end) {
                    idx = intervals[mid][2];
                    max = mid-1;
                } else {
                    min = mid+1;
                }
            }

            res[intervals[i][2]] = idx;
        }

        return res;
    }
};