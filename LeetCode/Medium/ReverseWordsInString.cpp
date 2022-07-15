class Solution {
public:
    string reverseWords(string s) {
        stringstream ss(s);
        
        string res = "";
        string word;
        
        while(ss>>word){
            res = word + " " + res;
        }
        
        int N = res.length();
        
        return res.substr(0, N-1);
    }
};