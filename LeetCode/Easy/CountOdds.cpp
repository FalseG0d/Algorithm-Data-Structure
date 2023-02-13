class Solution {
public:
    int countOdds(int low, int high) {
        int res = 0;

        if(low % 2 == 1) {
            res++;
            low++;
        }

        if(high % 2 == 1) {
            res++;
            high--;
        }

        res += ((high - low) / 2);

        return res;
    }
};