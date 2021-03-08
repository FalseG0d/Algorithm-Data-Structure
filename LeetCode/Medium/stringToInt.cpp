class Solution {
public:
    int myAtoi(string s) {
        stringstream ss(s);
        
        int n=0;
        ss>>n;
        
        return n;
    }
};