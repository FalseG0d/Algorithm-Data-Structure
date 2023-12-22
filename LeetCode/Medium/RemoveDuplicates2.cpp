class Solution {
public:
    int removeDuplicates(vector<int>& nums) {
        int N = nums.size();
        
        map<int,int>mp;
        
        for(auto itr=nums.begin();itr!=nums.end();++itr){
            if(mp[*itr] < 2) mp[*itr]++;
            else {
                nums.erase(itr);
                itr--;
            }
        }
        
        return nums.size();
    }
};