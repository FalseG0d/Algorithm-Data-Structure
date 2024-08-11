class Solution {
public:
    int trailingZeroes(int num) {
        int den = 5;
        int res = 0;

        while(num / den > 0) {
            res += num / den;

            den *= 5;
        }

        return res;
    }
};