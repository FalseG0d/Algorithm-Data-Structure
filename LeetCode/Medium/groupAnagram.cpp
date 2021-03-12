class Solution {
public:
    vector<vector<string>> groupAnagrams(vector<string>& strs) {
        map<vector<char>,vector<string>>mp;
        vector<vector<string>>res;
            
        for(int i=0;i<strs.size();i++){
            vector<char>s;
            for(int j=0;j<strs[i].length();j++){
                s.push_back(strs[i][j]);
            }
            sort(s.begin(),s.end());
            mp[s].push_back(strs[i]);
        }
        
        for(map<vector<char>,vector<string>>::iterator itr=mp.begin();itr!=mp.end();++itr){
            res.push_back(itr->second);
        }
        
        return res;
    }
};