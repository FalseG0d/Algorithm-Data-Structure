class Solution {
public:
    vector<int> findDisappearedNumbers(vector<int>& nums) {
        int N = nums.size();
        // for(int ele : nums) cout<<ele<<"\t";
        // cout<<"\n";
        
        for(int i=0;i<N;i++) {
            int itr = nums[i] >= 0 ? nums[i] : -nums[i];
            
            if(nums[itr - 1] > 0) nums[itr - 1] *= -1;
        }
        
        vector<int> res;
        
        for(int ele : nums) cout<<ele<<" ";
        
        for(int i=0;i<N;i++) {
            if(nums[i] > 0) res.push_back(i+1);
        }
        
        return res;
    }
};