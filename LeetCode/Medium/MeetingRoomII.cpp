class Compare {
    public:
       bool operator()(vector<int> v1, vector<int> v2){
           return v1[1] > v2[1];
      }
};

class Solution {
public:
    static bool compareFirsts(vector<int>&v1, vector<int>&v2) {
        return v1[0] < v2[0];
    }
    int minMeetingRooms(vector<vector<int>>& intervals) {
        std::sort(intervals.begin(), intervals.end(), compareFirsts);
        int N = intervals.size();

        int res = 1;
        int currInUse = 1;

        priority_queue<vector<int>, vector<vector<int>>, Compare>pq;
        pq.push(intervals[0]);

        for(int i=1;i<N;i++) {
            int currBeg = intervals[i][0];
            int currEnd = intervals[i][1];

            // // Empty all Meetings Over
            while(!pq.empty() && pq.top()[1] <= currBeg) {
                pq.pop();
                currInUse--;
            }

            pq.push(intervals[i]);
            currInUse++;

            res = max(res, currInUse);
        }

        return res;
    }
};