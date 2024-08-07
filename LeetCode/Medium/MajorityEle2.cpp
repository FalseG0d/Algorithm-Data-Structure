class Solution {
public:
    vector<int> majorityElement(vector<int>& nums) {
        int N = nums.size();

        int ele1 = 0;
        int ele2 = 0;

        int N1 = 0;
        int N2 = 0;

        for(int i=0;i<N;i++) {
            if(N1 == 0 && nums[i] != ele2) {
                N1 = 1;
                ele1 = nums[i];
            } else if(N2 == 0 && nums[i] != ele1) {
                N2 = 1;
                ele2 = nums[i];
            } else if(ele1 == nums[i]) {
                N1++;
            } else if(ele2 == nums[i]) {
                N2++;
            } else {
                N1--;
                N2--;
            }
        }

        vector<int>res = {};

        int cnt1 = 0;
        int cnt2 = 0;

        for(int ele : nums) {
            if(ele == ele1) cnt1++;
            if(ele == ele2 && ele1 != ele2) cnt2++;
        }

        if(cnt1 > nums.size() / 3) res.push_back(ele1);
        if(cnt2 > nums.size() / 3) res.push_back(ele2);

        return res;
    }
};