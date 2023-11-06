class Solution {
public:
    string countAndSay(int n) {
        if(n == 1) return "1";

        string str = countAndSay(n - 1);
        string ret = "";

        int N = str.length();
        int count = 1;
        
        char ch = str[0];

        for(int i=1;i<N;i++) {
            if(ch == str[i]) count++;
            else {
                ret += (to_string(count) + ch);
                
                count = 1;
                ch = str[i];
            }
        }

        ret += (to_string(count) + ch);

        return ret;
    }
};