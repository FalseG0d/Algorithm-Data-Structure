class Solution {
public:
    int singleNumber(vector<int>& nums) {
        map<int,int>mp;
        
        for(auto itr=nums.begin();itr!=nums.end();++itr){
            mp[*itr]++;
        }
        
        for(auto itr=nums.begin();itr!=nums.end();++itr){
            if(mp[*itr]==1)return *itr;
        }
        
        return -1;
    }
};