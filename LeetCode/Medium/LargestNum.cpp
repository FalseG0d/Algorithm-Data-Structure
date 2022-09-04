class Solution {
public:
    static bool compareNum(int a, int b){
        string num1 = std::to_string(a);
        string num2 = std::to_string(b);
        
        return num1 + num2 > num2 + num1;
    }
    string largestNumber(vector<int>& nums) {
        std::sort(nums.begin(), nums.end(), compareNum);
        
        string res = "";
        int N = nums.size();
        
        bool flag = true;
        
        for(int ele : nums){
            if(ele != 0){
                flag = false;
                break;
            }
        }
        if(flag) return "0";
        flag = true;
        
        for(int i = 0;i<N;i++){
            if(nums[i] == 0) {
                if(!flag) res += std::to_string(nums[i]);
                else flag = false;
            }
            else{
                res += std::to_string(nums[i]);
                flag = false;
            }
        }
        
        return res;
    }
};