class Solution {
public:
    int getDays(vector<int>& weights, int cap) {
        int curr = cap;
        int days = 1;

        int N = weights.size();

        for(int i=0;i<N;i++) {
            if(curr >= weights[i]) {
                curr -= weights[i];
            } else {
                i--;
                curr = cap;
                days++;
            }
        }

        return days;
    }
    int shipWithinDays(vector<int>& weights, int days) {
        int maxCap = 0;
        int minCap = -1;

        int res = 1;

        for(int ele: weights) {
            maxCap += ele;
            minCap = max(minCap, ele);
        }

        while(minCap <= maxCap) {
            int mid = minCap + (maxCap - minCap) / 2;
            int tmpDays = getDays(weights, mid);

            if(tmpDays <= days) {
                res = mid;
                maxCap = mid-1;
            } else {
                minCap = mid+1;
            }
        }

        return res;
    }
};