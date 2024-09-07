class Solution {
public:
    string removeDuplicateLetters(string s) {
        vector<int>freq(26, 0);
        vector<bool>seen(26, false);

        for(char ch: s) {
            freq[ch - 'a']++;
        }

        stack<char>tmp;

        for(char ch: s) {
            if(seen[ch - 'a']) {
                freq[ch - 'a']--;
                continue;
            }

            while(!tmp.empty() && tmp.top() > ch) {
                if(freq[tmp.top() - 'a'] == 0) break;

                seen[tmp.top() - 'a'] = false;
                tmp.pop();
            }
            
            freq[ch - 'a']--;
            seen[ch - 'a'] = true;
            tmp.push(ch);
        }

        string res = "";

        while(!tmp.empty()) {
            res = tmp.top() + res;
            tmp.pop();
        }

        return res;
    }
};