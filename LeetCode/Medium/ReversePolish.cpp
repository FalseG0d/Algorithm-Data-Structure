class Solution {
public:
    string performOpp(string num1, string num2, string token) {
        int n1 = stoi(num1);
        int n2 = stoi(num2);

        int res = 0;

        switch(token[0]) {
            case '+': res = n1 + n2; break;
            case '-': res = n1 - n2; break;
            case '*': res = n1 * n2; break;
            case '/': res = n1 / n2; break;
        }

        return to_string(res);
    }
    int evalRPN(vector<string>& tokens) {
        int N = tokens.size();
        stack<string>st;

        for(int i=0;i<N;i++) {
            string token = tokens[i];

            if(token == "+" || token == "-" || token == "*" || token == "/") {
                string num1 = st.top(); st.pop();
                string num2 = st.top(); st.pop();

                st.push(performOpp(num2, num1, token));
            } else {
                st.push(token);
            }
        }

        return stoi(st.top());
    }
};