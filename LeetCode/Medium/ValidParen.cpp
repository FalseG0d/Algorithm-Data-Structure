class Solution {
public:
    bool isValid(string str) {
        stack<char>st;

        for(char ch : str) {
            if(ch == '(' || ch == '{' || ch == '[') st.push(ch);
            else {
                if(st.empty()) return false;
                
                char top = st.top();

                if(top == '(' && ch == ')') st.pop();
                else if(top == '{' && ch == '}') st.pop();
                else if(top == '[' && ch == ']') st.pop();
                else return false;
            }
        }

        return st.empty();
    }
};