class Solution {
public:
    bool compare(string s1, string s2) {
        vector<int>map(26, 0);

        for(char ch:s1) map[ch - 97]++;

        for(char ch:s2) {
            map[ch - 97]--;

            if(map[ch - 97] < 0) return false;
        }

        return true;
    }
    bool checkInclusion(string ptr, string str) {
        int N1 = ptr.length();
        int N2 = str.length();

        if(N1 > N2) return false;

        int key = 0;
        int chk = 0;

        for(char ch : ptr) key += ch;
        for(int i=0;i<N1;i++) chk += str[i];

        bool res = false;

        for(int i=0;i<=N2-N1;i++) {
            if(chk == key) {
                // Possible Match
                res = compare(str.substr(i, N1), ptr);
            }

            chk -= str[i];
            chk += str[i+N1];

            if(res) break;
        }

        return res;
    }
};