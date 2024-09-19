class Solution {
public:
    vector<int> asteroidCollision(vector<int>& asteroids) {
        stack<int>st;
        for(int ele: asteroids) {
            if(st.empty()) st.push(ele);
            else {
                bool addAst = false;

                while(!st.empty()) {
                    int top = st.top();
                    st.pop();

                    int dirTop = top / abs(top);
                    int dirAst = ele / abs(ele);

                    if(dirTop == dirAst) {
                        st.push(top);
                        st.push(ele);
                        addAst = false;
                        break;
                    } else if(dirTop > 0) {
                        if(abs(ele) > abs(top)) {
                            addAst = true;
                            continue;
                        } else if(abs(ele) < abs(top)) {
                            st.push(top);
                            addAst = false;
                            break;
                        } else {
                            addAst = false;
                            break;
                        }
                    } else {
                        st.push(top);
                        st.push(ele);
                        addAst = false;
                        break;
                    }
                }

                if(addAst) st.push(ele);
            }
        }

        vector<int>res;
            
        while(!st.empty()) {
            res.push_back(st.top());
            st.pop();
        }

        reverse(res.begin(), res.end());

        return res;
    }
};