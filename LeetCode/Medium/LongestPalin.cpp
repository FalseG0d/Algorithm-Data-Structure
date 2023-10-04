class Solution {
public:
    string longestPalindrome(string s) {
        int N = s.length();

        int beg = -1;
        int end = -1;

        int resLen = 0;
        string res = "";

        for(int i=0;i<N;i++) {
            // Odd Len Palindrome

            beg = i;end = i;
            while(beg >=0 && end < N && s[beg] == s[end]) {
                if(resLen < end - beg + 1) {
                    resLen = end - beg + 1;
                    res = s.substr(beg, resLen);
                }

                beg--;
                end++;
            }
            // Even Len Palindrome

            beg = i;end = i + 1;
            while(beg >=0 && end < N && s[beg] == s[end]) {
                if(resLen < end - beg + 1) {
                    resLen = end - beg + 1;
                    res = s.substr(beg, resLen);
                }

                beg--;
                end++;
            }
        }

        return res;
    }
};