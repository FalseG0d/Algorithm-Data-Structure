class Solution {
public:
    string getKey(string str) {
        vector<int>mp(26, 0);
        for(char ch : str) mp[ch - 97]++;

        string key = "";
        
        for(int i=0;i<26;i++) {
            if(mp[i] > 0) {
                key += (char)(i + 97) + to_string(mp[i]);
            }
        }

        return key;
    }
    vector<vector<string>> groupAnagrams(vector<string>& strs) {
        unordered_map<string, vector<string>> mp;
        vector<vector<string>> res;

        for(string str : strs) {
            mp[getKey(str)].push_back(str);
        }

        for(auto itr=mp.begin();itr!=mp.end();++itr) {
            res.push_back(itr->second);
        }

        return res;
    }
};