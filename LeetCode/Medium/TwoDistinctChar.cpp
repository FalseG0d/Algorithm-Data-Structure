class Solution {
public:
    int lengthOfLongestSubstringTwoDistinct(string s) {
        int N = s.length();

        int beg = 0;
        int end = 0;

        int distinctChar = 0;

        int res = 0;

        unordered_map<char, int>mp;

        while(end < N) {
            mp[s[end]]++;

            if(mp[s[end]] == 1) {
                // New Character encountered
                distinctChar++;
            }

            while(distinctChar > 2) {
                mp[s[beg]]--;
                if(mp[s[beg]] == 0) {
                    // Character No Longer in window

                    distinctChar--;
                }
                beg++;
            }

            res = max(res, end - beg + 1);
            end++;
        }

        return res;
    }
};