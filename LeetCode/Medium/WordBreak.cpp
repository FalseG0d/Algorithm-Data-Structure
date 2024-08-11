class Solution {
    int*dp;
public:
    bool wordBreakHelp(string& str, int beg, vector<string>& wordDict) {
        if(beg >= str.length()) return true;
        if(dp[beg] != -1) return dp[beg];

        for(string word: wordDict) {
            if(str.substr(beg, word.length()) == word) {
                if(wordBreakHelp(str, beg + word.length(), wordDict)) {
                    return dp[beg] = true;
                }
            }
        }

        return dp[beg] = false;
    }

    bool wordBreak(string str, vector<string>& wordDict) {
        int N = str.length();
        
        dp = new int[N];
        for(int i=0;i<N;i++) dp[i] = -1;
        
        return wordBreakHelp(str, 0, wordDict);
    }
};