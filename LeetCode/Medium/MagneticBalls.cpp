class Solution {
public:
    bool canPlace(vector<int>& position, int gap, int m) {
        int N = position.size();

        int placed = 1;
        int last = position[0];

        for(int i=0;i<N;i++) {
            if(position[i] - last >= gap) {
                last = position[i];
                placed++;
            }
        }

        return placed >= m;
    }
    int maxDistance(vector<int>& position, int m) {
        sort(position.begin(), position.end());
        
        int N = position.size();

        int lo = 1;
        int hi = position[N-1] - position[0];

        int res = 0;

        while(lo <= hi) {
            int gap = lo + (hi - lo) / 2;

            if(canPlace(position, gap, m)) {
                res = gap;
                lo = gap + 1;
            } else {
                hi = gap - 1;
            }
        }

        return res;
    }
};