class Solution {
public:
    char toLower(char ch){
        if(ch<='Z'&&ch>='A')return (ch+32);
        else return ch;
    }
    bool check(char ch){
        return !((ch<='Z'&&ch>='A')||(ch<='z'&&ch>='a')||(ch<='9'&&ch>='0'));
    }
    bool isPalindrome(string s) {
        int itr1=0,itr2=s.length()-1;
        
        while(itr1<=itr2){
            if(check(s[itr1])){itr1++;continue;}
            if(check(s[itr2])){itr2--;continue;}
            
            if(toLower(s[itr2])!=toLower(s[itr1]))return false;
            
            itr1++;itr2--;
        }
        
        return true;
    }
};