class Solution {
public:
    vector<vector<int>>res;
    
    void help(vector<int>v,int pos){
        if(pos==v.size()-1){
            res.push_back(v);

            return;
        }
        
        for(int i=pos;i<v.size();i++){
            swap(v[pos],v[i]);
            help(v,pos+1);
            swap(v[pos],v[i]);
        }

        return;
    }
    
    vector<vector<int>> permute(vector<int>& nums) {
        help(nums,0);
        
        return res;
    }
};