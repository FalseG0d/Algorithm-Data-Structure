class Solution {
public:
    void help(int open, int close, int &n, vector<string> &res, string str) {
        if(open > n || close > n) return;
        if(open + close == 2 * n) {
            cout<<str<<"\n";
            res.push_back(str);
            return;
            }

        if(open > close) {
            // Can Place Both Open and Closing Bracket

            help(open + 1, close, n, res, str + "(");
            help(open, close + 1, n, res, str + ")");
        } else if(open == close){
            // Can Only Place Open Bracket
            help(open + 1, close, n, res, str + "(");
        } else {
            // Invalid Case
            return;
        }
    }

    vector<string> generateParenthesis(int n) {
        vector<string> res;

        help(0, 0, n, res, "");

        return res;
    }
};