class Solution {
public:
    static int mod(int n){
        if(n<0)return -n;
        else return n;
    }
    int threeSumClosest(vector<int>& nums, int target) {
        int res=nums[0]+nums[1]+nums[2];
        int n=nums.size();
        
        sort(nums.begin(),nums.end());
        
        for(int i=0;i<n-2;i++){
            int l=i+1;
            int r=n-1;
            int sum;            
            
            while(l<r){
                sum=nums[i]+nums[l]+nums[r];
                
                if(sum>target)r--;
                else if(sum<target)l++;
                else {
                    res=sum;
                    
                    l++;
                }
                
                if(mod(res-target)>mod(sum-target))res=sum;
            }
            
        }
        
        return res;
    }
};