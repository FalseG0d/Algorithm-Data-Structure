class Solution {
    vector<string>comb = {"", "", "abc", "def", "ghi", "jkl", "mno", "pqrs", "tuv", "wxyz"};
public:
    string getString(char ch) {
        string str(1, ch);
    
        return str;   
    }
    vector<string> help(string digits, int curr) {
        vector<string> res;
        if(curr == digits.length() - 1) {
            for(char ch : comb[digits[curr] - '0']) {
                res.push_back(getString(ch));
            }
            return res;
        }

        for(char ch : comb[digits[curr] - '0']) {
            for(string str : help(digits, curr+1)) {
                res.push_back(ch + str);
            }
        }
        
        return res;
    }
    vector<string> letterCombinations(string digits) {
        if(digits.length() == 0) return {};

        return help(digits, 0);
    }
};