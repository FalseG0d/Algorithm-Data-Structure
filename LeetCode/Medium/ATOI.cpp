class Solution {
public:
    bool isDigit(char ch) {
        return ch >= '0' && ch <= '9';
    }
    int myAtoi(string s) {
        int N = s.length();
        int itr = 0;
        int sign = 1;

        while(itr < N && s[itr] == ' ') itr++;
        s = s.substr(itr);

        N = s.length();
        itr = 0;

        double res = 0;

        if(s[0] == '-' || s[0] == '+') {
            if(s[0] == '-') sign = -1;
            itr++;
            }

        while(itr < N) {
            if(isDigit(s[itr])) {
                if(sign * (res * 10 + s[itr] - '0') > INT_MAX) return INT_MAX;
                else if(sign * (res * 10 + s[itr] - '0') < INT_MIN) return INT_MIN;
                else res = res * 10 + s[itr] - '0';
            } else {
                break;
            }

            itr++;
        }

        return sign * res;
    }
};