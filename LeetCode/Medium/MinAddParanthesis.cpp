class Solution {
public:
    int minAddToMakeValid(string str) {
        int cnt = 0;
        int res = 0;

        for(char ch : str) {
            if(ch == '(') cnt++;
            else if(ch == ')') cnt--;

            if(cnt < 0) {
                res++;
                cnt++;
            }
        }

        return res + abs(cnt);
    }
};