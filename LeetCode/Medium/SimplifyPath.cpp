class Solution {
public:
    string simplifyPath(string path) {
        std::replace(path.begin(), path.end(), '/', ' ');
        stringstream ss(path);

        string curr = "";
        deque<string>st;

        while(ss>>curr) {
            if(curr == "..") {
                if(!st.empty()) st.pop_back();
            } else {
                if(curr == ".") continue;
                st.push_back(curr);
            }
        }

        string res = "";

        while(!st.empty()) {
            res += ("/" + st.front());
            st.pop_front();
        }

        if(res.length() == 0) res = "/";

        return res;
    }
};