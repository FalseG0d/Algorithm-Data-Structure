class Solution {
public:
    int hIndex(vector<int>& citations) {
        int N = citations.size();

        int beg = 0;
        int end = N-1;
        int res = 0;
        
        while(beg <= end) {
            int mid = beg + (end - beg) / 2;

            if(N-mid >= citations[mid]) {
                res = max(res, citations[mid]);
                beg = mid + 1;
            } else {
                res = max(res, N-mid);
                end = mid - 1;
            }
        }

        return res;
    }
};