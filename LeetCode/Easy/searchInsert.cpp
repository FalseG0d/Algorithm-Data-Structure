class Solution {
public:
    int searchInsert(vector<int>& v, int target) {
        v.push_back(target);
        
        sort(v.begin(),v.end());
        
        return (int)(std::find(v.begin(),v.end(),target)-v.begin());
    }
};