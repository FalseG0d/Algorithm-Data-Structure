class Solution {
public:
    int getLongestValidParentheses(string str) {
        int left = 0;
        int right = 0;

        int itr = 0;
        int N = str.length();
        int res = 0;

        while(itr < N) {
            if(str[itr] == '(') left++;
            else right++;

            if(right == left) res = max(res, left + right);
            else if(right > left) left = right = 0;
            itr++;
        }

        return res;
    }
    int longestValidParentheses(string s) {
        int left = getLongestValidParentheses(s);
        int N = s.length();
        reverse(s.begin(), s.end());
        for(int i=0;i<N;i++) {
            if(s[i] == '(') s[i] = ')';
            else s[i] = '(';
        }
        int rght = getLongestValidParentheses(s);

        return max(left, rght);
    }
};