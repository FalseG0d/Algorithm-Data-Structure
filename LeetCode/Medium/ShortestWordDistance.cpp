class Solution {
public:
    int help1(vector<string>& wordsDict, string word1, string word2) {
        int res = wordsDict.size();
        
        int pos1 = -1;
        int pos2 = -1;

        int itr = 0;

        for(string word : wordsDict) {
            if(word == word1) {
                if(pos2 != -1) {
                    res = min(res, abs(itr - pos2));
                }

                pos1 = itr;
            }
            if(word == word2) {
                if(pos1 != -1) {
                    res = min(res, abs(itr - pos1));
                }

                pos2 = itr;
            }

            itr++;
        }

        return res;
    }
    int help2(vector<string>& wordsDict, string word) {
        int res = wordsDict.size();
        
        int prev = -1;
        int curr = -1;

        int itr = 0;

        for(string str : wordsDict) {
            if(str == word) {
                if(curr == -1) {
                    // Do Nothing
                } else {
                    prev = curr;
                    res = min(res, abs(itr - prev));
                }

                curr = itr;
            }

            itr++;
        }

        return res;
    }
    int shortestWordDistance(vector<string>& wordsDict, string word1, string word2) {
        if(word1 == word2) {
            return help2(wordsDict, word1);
        }
        else {
            return help1(wordsDict, word1, word2);
        }
    }
};