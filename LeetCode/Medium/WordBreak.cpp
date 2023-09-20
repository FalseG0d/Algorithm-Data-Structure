class Solution {
public:
    int*dp;
    int help(string &s, vector<string>& wordDict, int pos){
        if(pos == s.length()) return true;
        if(dp[pos] != -1) return dp[pos];
        
        bool res;
        
        for(string word: wordDict){
            int len = word.length();
            
            string sub = s.substr(pos, len);
            
            if(sub == word) res = help(s, wordDict, pos + len);
            
            if(res) break;
        }
        
        return dp[pos] = res;
    }
    bool wordBreak(string s, vector<string>& wordDict) {
        dp = new int[s.length() + 1];
        
        for(int i=0;i<=s.length();i++) dp[i] = -1;
        
        help(s, wordDict, 0);
        
        return dp[0];
    }
};