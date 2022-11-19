class Solution {
public:
    vector<int> intersect(vector<int>& nums1, vector<int>& nums2) {
        unordered_map<int,int>countInOne;
        unordered_map<int,int>countInTwo;
        
        for(int ele : nums1) countInOne[ele]++;
        for(int ele : nums2) {
            if(countInOne[ele] > 0) {
                countInOne[ele]--;
                countInTwo[ele]++;
            }
        }
        
        // for(auto itr=mp.begin();itr!=mp.end();++itr) cout<<itr->first<<"->"<<itr->second<<"\n";
        
        vector<int>res;
        
        for(auto itr=countInTwo.begin();itr!=countInTwo.end();++itr){
            for(int i=0;i<itr->second;i++) res.push_back(itr->first);
        }
        
        return res;
    }
};