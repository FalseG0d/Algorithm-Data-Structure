class Solution {
public:
    string choices(char ch){
        switch(ch){
            case '2': return "abc";
            case '3': return "def";
            case '4': return "ghi";
            case '5': return "jkl";
            case '6': return "mno";
            case '7': return "pqrs";
            case '8': return "tuv";
            case '9': return "wxyz";
        }
        
        return "";
    }
    
    string stringToChar(char ch){
        string s(1,ch);
        
        return s;
    }
    
    void help(vector<string>&res,string digits){
        if(digits=="")return;
        
        string charChoices=choices(digits[0]);
        vector<string>tempRes;
        
        
        for(int i=0;i<res.size();i++){
            for(int j=0;j<charChoices.length();j++){
                tempRes.push_back(res[i]+charChoices[j]);
            }
        }
        
        res=tempRes;
        
        digits.erase(digits.begin());
        
        help(res,digits);
    }
    
    vector<string> letterCombinations(string digits) {
        vector<string>res;
        
        if(digits=="")return res;
        
        string temp=choices(digits[0]);
        
        for(char ch:temp)res.push_back(stringToChar(ch));
        
        digits.erase(digits.begin());
        help(res,digits);
        
        return res;
    }
};