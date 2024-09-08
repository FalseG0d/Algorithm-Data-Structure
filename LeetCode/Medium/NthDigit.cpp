class Solution {
public:
    int findNthDigit(int n) {
        if(n < 10) return n;

        n -= 10;
        int digits = 2;
        double diff = 90;

        while(n - diff * digits >= 0) {
            n -= diff * digits;

            diff *= 10;
            digits++;
        }

        int num = pow(10, digits-1) + n / digits;
        return stoi(to_string(num).substr(n % digits, 1));
    }
};