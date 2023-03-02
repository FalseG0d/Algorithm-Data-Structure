class Solution {
public:
    int compress(vector<char>& chars) {
        string res = "";
        char prev = '\0';
        int count = 0;

        for(char ch : chars) {
            if(prev != ch) {
                if(count > 1) res += to_string(count);
                res += ch;

                count = 1;
                prev = ch;
            }else{
                count++;
            }
        }

        if(count > 1) res += to_string(count);

        chars.clear();

        for(char ch : res) chars.push_back(ch);

        cout<<res<<"\n";
        return res.size();
    }
};