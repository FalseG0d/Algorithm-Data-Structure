class Solution {
    vector<vector<int>>ops = {{1, 0}, {0, 1}, {-1, 0}, {0, -1}};
public:
    bool wordSearch(vector<vector<char>>& board, string& word, int pos, int p, int q) {
        if(pos == word.length()) return true;
        if(p < 0 || q < 0 || p == board.size() || q == board[0].size()) return false;
        if(board[p][q] != word[pos]) return false;

        char tmp = board[p][q];
        board[p][q] = '0';

        for(vector<int> op : ops) {
            int newP = p + op[0];
            int newQ = q + op[1];

            bool res = wordSearch(board, word, pos+1, newP, newQ);

            if(res) return res;
        }

        board[p][q] = tmp;

        return false;
    }
    bool exist(vector<vector<char>>& board, string word) {
        int M = board.size();
        int N = board[0].size();

        unordered_map<char, int>mp;

        for(int i=0;i<M;i++) {
            for(int j=0;j<N;j++) {
                mp[board[i][j]]++;
            }
        }

        for(char ch : word) {
            mp[ch]--;

            if(mp[ch] < 0) return false;
        }

        for(int i=0;i<M;i++) {
            for(int j=0;j<N;j++) {
                bool res = wordSearch(board, word, 0, i, j);

                if(res) return res;
            }
        }

        return false;
    }
};