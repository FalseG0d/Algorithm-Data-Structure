class Solution {
public:
    int maxOf(int a, int b, int c){
        if(a > b){
            return a > c ? a : c;
        }else{
            return b > c ? b : c;
        }
    }
    int minOf(int a, int b, int c){
        if(a < b){
            return a < c ? a : c;
        }else{
            return b < c ? b : c;
        }
    }
    int getMaxEle(vector<int>& nums) {
        int N = nums.size();
        int res = INT_MIN;
        for(int i=0;i<N;i++){
            res = max(res, nums[i]);
        }
        return res;
    }
    int maxProduct(vector<int>& nums) {
        int res = getMaxEle(nums);
        int N = nums.size();      
        int currMin = 1;
        int currMax = 1;
        for(int i=0;i<N;i++){
            if(nums[i] == 0){
                currMin = currMax = 1;
                continue;
            }
            int temp = currMax * nums[i];
            currMax = maxOf(currMax * nums[i], currMin * nums[i], nums[i]);
            currMin = minOf(temp, currMin * nums[i], nums[i]);
            res = max(res, currMax);
        }       
        return res;
    }
};