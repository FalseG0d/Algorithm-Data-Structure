class Solution {
public:    
    vector<vector<int>> subsetsWithDup(vector<int>& nums) {
        vector<vector<int>> tmpRes;
        vector<int>temp;
        
        sort(nums.begin(),nums.end());
        
        tmpRes.push_back(temp);
        
        for(int ele : nums){
            int n = tmpRes.size();

            for(int i=0;i<n;i++){
                tmpRes[i].push_back(ele);    
                tmpRes.push_back(tmpRes[i]);
                tmpRes[i].pop_back();
            }
        }
        
        set<vector<int>>res(tmpRes.begin(), tmpRes.end());
        
        return vector<vector<int>>(res.begin(),res.end());
    }
};