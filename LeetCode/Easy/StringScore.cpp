class Solution {
public:
    int scoreOfString(string str) {
        int N = str.length();
        int res = 0;

        for(int i=0;i<N-1;i++) {
            res += abs(str[i] - str[i+1]);
        }

        return res;
    }
};