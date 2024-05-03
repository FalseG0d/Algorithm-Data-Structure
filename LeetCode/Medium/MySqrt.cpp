class Solution {
public:
    int mySqrt(int x) {
        int beg = 0;
        int end = x;

        double mid = x;

        while(beg <= end) {
            mid = beg + (end - beg) / 2;

            if(mid * mid == x) break;
            else if(mid * mid < x) beg = mid + 1;
            else end = mid - 1;
        }

        return mid * mid <= x ? mid : mid - 1;
    }
};