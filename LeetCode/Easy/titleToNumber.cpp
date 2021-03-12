class Solution {
public:
    int titleToNumber(string columnTitle) {
        int res=0;
        
        for(char ch:columnTitle){
            res*=26;
            res+=ch-64;
        }
        
        return res;
    }
};