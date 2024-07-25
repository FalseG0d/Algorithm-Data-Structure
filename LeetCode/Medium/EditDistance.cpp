class Solution {
    int**dp;
public:
    int help(int itr1, int itr2, string &word1, string &word2) {
        if(itr1 == word1.length()) return word2.length() - itr2;
        if(itr2 == word2.length()) return word1.length() - itr1;

        if(dp[itr1][itr2] != -1) return dp[itr1][itr2];

        if(word1[itr1] == word2[itr2]) return dp[itr1][itr2] = help(itr1+1,itr2+1,word1,word2);
        else return dp[itr1][itr2] = 1 + min(
            help(itr1+1, itr2, word1, word2),
            min(help(itr1+1, itr2+1, word1, word2), help(itr1, itr2+1, word1, word2)));
    }
    int minDistance(string word1, string word2) {
        dp = new int*[word1.length() + 1];
        
        for(int i=0;i<word1.length()+1;i++)
            dp[i] = new int[word2.length() + 1];

        for(int i=0;i<=word1.length();i++) {
            for(int j=0;j<=word2.length();j++) dp[i][j] = -1;
        }
        
        return help(0, 0, word1, word2);
    }
};