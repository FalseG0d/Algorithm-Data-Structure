class Solution {
public:
    bool isValid(string str) {
        stack<int> s;
        
        for(int i=0;i<str.length();i++){
            if(str[i]=='('||str[i]=='['||str[i]=='{'){
                s.push(str[i]);
            }else{
                if(s.empty())return false;
                
                if(str[i]==')'&&s.top()=='(')s.pop();
                else if(str[i]=='}'&&s.top()=='{')s.pop();
                else if(str[i]==']'&&s.top()=='[')s.pop();
                else return false;
            }
        }
        
        return s.empty();
    }
};