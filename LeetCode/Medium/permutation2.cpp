class Solution {
public:
    set<vector<int>>res;
    
    void help(vector<int>v,int curr){
        if(curr==v.size()-1){
            res.insert(v);
            return;
        }
        
        for(int i=curr;i<v.size();i++){
            swap(v[i],v[curr]);
            help(v,curr+1);
            swap(v[i],v[curr]);
        }
    }
    
    vector<vector<int>> permuteUnique(vector<int>& nums) {
        vector<int>curr;
        
        help(nums,0);
        
        vector<vector<int>>s(res.begin(),res.end());
        
        return s;
    }
};