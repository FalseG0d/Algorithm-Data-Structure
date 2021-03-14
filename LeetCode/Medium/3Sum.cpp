class Solution {
public:
    vector<vector<int>> threeSum(vector<int>& nums) {
        vector<vector<int>>res;
        int sum=0;
        int n=nums.size();
        
        for(int i=0;i<n-2;i++){
            vector<int>temp;
            sum+=nums[i];
            for(int j=i+1;j<n-1;j++){
                sum+=nums[j];
                for(int k=j+1;k<n;k++){
                    sum+=nums[k];
                    if(sum==0&&temp.size()<3){
                        temp.push_back(nums[i]);
                        temp.push_back(nums[j]);
                        temp.push_back(nums[k]);
                        
                        res.push_back(temp);
                        }
                    sum-=nums[k];
                    if(temp.size()>=3)temp.pop_back();
                }sum-=nums[j];
                if(temp.size()>=2)temp.pop_back();
            }sum-=nums[i];
            if(temp.size()>=1)temp.pop_back();
        }
        
        return res;
    }
};