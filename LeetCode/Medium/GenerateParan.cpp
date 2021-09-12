class Solution {
public:
    vector<string>res;
    
    void help(string curr, int open, int close, int max){
        if(curr.length() == 2 * max){
            res.push_back(curr);
            return;
            }
        
        if(open < max) help(curr + "(", open + 1, close, max);
        if(open > close) help(curr + ")", open, close + 1, max);
    }
    
    vector<string> generateParenthesis(int n) {
        help("", 0, 0, n);
        
        return res;
    }
};