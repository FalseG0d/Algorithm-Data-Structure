class Solution {
public:
    int lengthOfLastWord(string s) {
        stringstream ss(s);
        string word = "";
        string res = "";

        while(ss) {
            word = "";
            ss>>word;

            if(word.length() == 0) break;
            res = word;
        }

        return res.length();
    }
};