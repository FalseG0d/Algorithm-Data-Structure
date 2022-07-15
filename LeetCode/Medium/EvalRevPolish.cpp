class Solution {
public:
    int getRes(int x, int y, string opr){
        if(opr == "+") return y + x;
        else if(opr == "-") return y - x;
        else if(opr == "*") return y * x;
        else  return y / x;
    }
    int evalRPN(vector<string>& tokens) {
        stack<int>s;
        
        for(string str:tokens){
            if(str == "+" || str == "-" || str == "*" || str == "/"){
                int x = s.top();
                s.pop();
                int y = s.top();
                s.pop();
                
                int res = getRes(x, y, str);
                
                s.push(res);
            }else{
                stringstream ss(str);
                int x = 0;
                ss>>x;
                
                s.push(x);
                }
        }
        
        return s.top();
    }
};