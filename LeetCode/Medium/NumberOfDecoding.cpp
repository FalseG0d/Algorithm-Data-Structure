class Solution {
    int*dp;
public:
    int numberOfDecoding(string& str, int beg) {
        if(beg > str.length()) return 0;
        if(beg == str.length()) return 1;

        if(dp[beg] != -1) return dp[beg];

        int cnt = 0;

        for(int i=1;i<=2;i++) {
            int num = stoi(str.substr(beg, i));

            if(num == 0) return dp[beg] = 0;
            
            if(num > 0 && num < 27) {
                cnt += numberOfDecoding(str, beg + i);
            }
        }

        return dp[beg] = cnt;
    }
    int numDecodings(string s) {
        dp = new int[s.length()];
        for(int i=0;i<s.length();i++) dp[i] = -1;
        return numberOfDecoding(s, 0);
    }
};