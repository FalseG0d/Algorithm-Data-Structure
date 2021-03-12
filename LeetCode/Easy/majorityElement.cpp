class Solution {
public:
    int majorityElement(vector<int>& v) {
        map<int,int>mp;
        
        for(int i=0;i<v.size();i++){
            mp[v[i]]++;
        }
        
        int max=INT_MIN;
        int val;
        for(auto itr=mp.begin();itr!=mp.end();++itr){
            if(itr->second>max){
                max=itr->second;
                val=itr->first;
            }
        }
        
        return val;
    }
};