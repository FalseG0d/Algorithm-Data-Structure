class Solution {
public:
    string getHint(string secret, string guess) {
        unordered_map<int,int>mp;
        int N = secret.length();

        int x = 0;
        int y = 0;

        for(int i=0;i<N;i++) {
            mp[guess[i] - '0']++;
        }

        for(int i=0;i<N;i++) {
            if(secret[i] == guess[i]) {
                x++;
                mp[guess[i] - '0']--;
                secret[i] = 'A';
            }
        }

        for(int i=0;i<N;i++) {
            if(secret[i] == 'A') continue;
            
            if(mp[secret[i] - '0'] > 0) {
                y++;
            }

            mp[secret[i] - '0']--;
        }

        return to_string(x) + "A" + to_string(y) + "B";
    }
};