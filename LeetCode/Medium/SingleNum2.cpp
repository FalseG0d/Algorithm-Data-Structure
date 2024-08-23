class Solution {
public:
    int singleNumber(vector<int>& nums) {
        int itr = 1;
        int res = 0;

        for(int i=0;i<32;i++) {
            int cnt = 0;

            for(int ele: nums) {
                cnt += (ele >> i) & 1 > 0;
            }

            if(cnt % 3 == 1) res += (1 << i);
        }
        
        return res;
    }
};