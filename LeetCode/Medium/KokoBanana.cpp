class Solution {
public:
    long long getHours(vector<int> piles, int K) {
        int N = piles.size();
        long long res = 0;

        for(int i=0;i<N;i++) {
            res += (piles[i] / K) + (piles[i] % K > 0 ? 1 : 0);
        }

        return res;
    }
    int minEatingSpeed(vector<int>& piles, int h) {
        int N = piles.size();

        int beg = 1;
        int end = 1;

        for(int ele : piles) {
            end = max(end, ele);
        }

        int MIN = 1;
        int MAX = end;

        int res = 1;

        while(beg <= end) {
            int mid = beg + (end - beg) / 2;
            long long curr = getHours(piles, mid);

            // cout<<mid<<":"<<curr<<"\n";

            if(curr <= h) {
                res = mid;
                end = mid - 1;
            } else {
                beg = mid + 1;
            }
        }

        return res;
    }
};