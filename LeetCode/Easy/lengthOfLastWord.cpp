class Solution {
public:
    int lengthOfLastWord(string s) {
        int res=0;
        
        for(int i=0;i<s.size();i++){
            if(s[i]==32&&(s[i+1]==32||s[i+1]=='\0'))continue;
            if(s[i]==32)res=0;
            else res++;
        }
        
        return res;
    }
};