class Solution {
public:
    bool help(string s) {
        int open = 0;
        int star = 0;

        for(char ch: s) {
            if(ch == '(') open++;
            else if(ch == ')') open--;
            else star++;

            if(open < 0) {
                if(abs(open) > star) return false;
                else {
                    star -= abs(open);
                    open = 0;
                }
            }
        }

        if(star >= abs(open)) return true;
        else return false;
    }
    bool checkValidString(string s) {
        string str = s;
        string rev = "";

        for(int i=s.length()-1;i>=0;i--) {
            if(s[i] == '(') rev += ")";
            else if(s[i] == ')') rev += "(";
            else rev += "*";
        }

        return help(str) && help(rev);
    }
};