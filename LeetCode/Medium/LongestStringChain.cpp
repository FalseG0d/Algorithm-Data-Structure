class Solution {
public:
    static bool compare(string word1, string word2) {
        if(word1.length() == word2.length()) return word1 < word2;
        else return word1.length() < word2.length();
    }
    int longestStrChain(vector<string>& words) {
        sort(words.begin(), words.end(), compare);
        
        int N = words.size();
        vector<int>dp(N, 1);

        for(int i=0;i<N;i++) {
            for(int j=0;j<i;j++) {
                if(words[i].length() - words[j].length() == 1) {
                    int N1 = words[i].length();
                    int N2 = words[j].length();

                    int itr1 = 0;
                    int itr2 = 0;

                    while(itr1 < N1 && itr2 < N2) {
                        if(words[i][itr1] == words[j][itr2]) {
                            itr1++;
                            itr2++;
                        } else {
                            itr1++;
                        }
                    }

                    if(itr1 == itr2 || itr1 - itr2 == 1) {
                        dp[i] = max(dp[i], 1 + dp[j]);
                    }
                } else continue;
            }
        }

        int maxEle = -1;

        for(int ele : dp) maxEle = max(maxEle, ele);

        return maxEle;
    }
};