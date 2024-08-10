class Solution {
public:
    int candy(vector<int>& ratings) {
        int N = ratings.size();
        vector<int>candyCount(N, 1);

        for(int i=1;i<N;i++) {
            if(ratings[i] - ratings[i-1] > 0) {
                candyCount[i] = candyCount[i-1] + 1;
            }
        }

        for(int i=N-2;i>=0;i--) {
            if(ratings[i] - ratings[i+1] > 0) {
                candyCount[i] = max(candyCount[i], candyCount[i+1] + 1);
            }
        }

        int res = 0;
        for(int ele: candyCount) res += ele;

        return res;
    }
};