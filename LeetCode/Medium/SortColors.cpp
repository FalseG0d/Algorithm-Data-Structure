class Solution {
public:
    void sortColors(vector<int>& nums) {
        vector<int>colors(3,0);
        for(int ele : nums) colors[ele]++;
        
        int itr = 0;
        int N = nums.size();
        int curr = 0;
        
        while(itr < N){
            while(curr < 3 && colors[curr] == 0) curr++;
            nums[itr++] = curr;
            colors[curr]--;
        }
    }
};