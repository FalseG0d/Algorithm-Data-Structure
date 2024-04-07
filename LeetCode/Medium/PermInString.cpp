class Solution {
public:
    bool checkPerm(string s1, string s2) {
        // cout<<s1<<" "<<s2<<"\n";

        unordered_map<char, int> mp;

        for(char ch : s2) {
            mp[ch]++;
        }

        for(char ch : s1) {
            mp[ch]--;

            if(mp[ch] == -1) return false;
        }

        return true;
    }
    bool checkInclusion(string s1, string s2) {
        int l1 = s1.length();
        int l2 = s2.length();

        if(l1 > l2) return false;

        int key = 0;
        int chk = 0;

        for(int i=0;i<l1;i++) key += s1[i];
        for(int i=0;i<l1;i++) chk += s2[i];

        for(int i=0;i<l2-l1;i++) {
            // cout<<s1<<" "<<s2.substr(i, l1)<<"\n";
            if(key == chk) {
                if(checkPerm(s1, s2.substr(i, l1))) return true;
            }

            chk -= s2[i];
            chk += s2[i + l1];
        }

        if(key == chk) {
            // cout<<s1<<" "<<s2.substr(l2-l1, l1)<<"\n";
            if(checkPerm(s1, s2.substr(l2-l1, l1))) return true;
        }

        return false;
    }
};