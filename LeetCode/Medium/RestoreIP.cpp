class Solution {
public:
    vector<string> help(string& str, int len, int cnt) {
        if(len <= 0) return {};
        if(len > cnt * 3) return {};
        
        if(cnt == 1) {
            string curr = str.substr(0, len);
            
            if(stoi(curr) > 255) return {};
            if(curr.length() > 1 && curr[0] == '0') return {};
            
            return {curr};
        }

        vector<string> res;

        for(int i=1;i<4;i++) {
            if(len - i < 0) continue;

            string curr = str.substr(len-i, i);

            if(stoi(curr) > 255 || (curr.length() > 1 && curr[0] == '0')) continue;

            vector<string>tmpRes = help(str, len-i, cnt-1);

            for(string tmp: tmpRes) {
                res.push_back(tmp + "." + curr);
            }
        }

        return res;
    }
    vector<string> restoreIpAddresses(string s) {
        return help(s, s.length(), 4);
    }
};