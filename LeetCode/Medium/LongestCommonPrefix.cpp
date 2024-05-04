class Solution {
public:
    int min(int a, int b) {
        return a < b ? a : b;
    }
    string longestCommonPrefix(vector<string>& strs) {
        int N = strs.size();

        sort(strs.begin(), strs.end());

        string str1 = strs[0];
        string str2 = strs[N-1];

        int len = min(str1.length(), str2.length());
        int count = 0;

        for(int i=0;i<len;i++) {
            if(str1[i] == str2[i]) count++;
            else break;
        }

        return str1.substr(0, count);
    }
};