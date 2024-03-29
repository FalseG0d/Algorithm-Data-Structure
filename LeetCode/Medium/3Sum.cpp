class Solution {
public:
    vector<vector<int>> threeSum(vector<int>& nums) {
        int n=nums.size();
        set<vector<int>>res;
        
        sort(nums.begin(),nums.end());
        
        for(int i=0;i<n-2;i++){
            if(i>0 && nums[i]==nums[i-1])continue;
            
            int l=i+1,r=n-1;
                    
            while(l<r){
                int sum=nums[i]+nums[l]+nums[r];
                
                if(sum==0){
                    vector<int>temp;
                    
                    temp.push_back(nums[i]);
                    temp.push_back(nums[l]);
                    temp.push_back(nums[r]);
                    
                    res.insert(temp);
                    
                    l++;
                    
                    if(nums[l]==nums[l-1]) l++;
                }else if(sum<0){
                    l++;
                }
                else {
                    r--;
                }
            }
            
        }
        
        vector<vector<int>>v(res.begin(),res.end());
        
        return v;
    }
};