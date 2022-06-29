class Solution {
public:
//     int singleNumber(vector<int>& nums) {
//         int N = nums.size();
        
//         if(N == 1) return nums[0];
        
//         sort(nums.begin(), nums.end());
        
//         if(nums[0] != nums[1]) return nums[0];
//         if(nums[N-1] != nums[N-2]) return nums[N-1];
        
//         int itr = 1;
        
//         while(itr < N){
//             if(nums[itr] != nums[itr-1]) return nums[itr-1];
            
//             itr += 3;
//         }
        
//         return -1;
//     }

    int singleNumber(vector<int>& nums) {
        int res = 0;
        unsigned int check = 1;
        
        for(int i=0;i<32;i++){
            int count = 0;
            for(int ele:nums){
                count += (ele&check)>0?1:0;
            }
            
            // cout<<count<<" : "<<check<<"\n";
            
            if(count % 3 != 0){
                res = res | check;
            }
            
            check = check * 2;
        }
        
        return res;
    }
};