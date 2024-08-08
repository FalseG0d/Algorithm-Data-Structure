class Solution {
public:
    vector<int> largestDivisibleSubset(vector<int>& nums) {
        int N = nums.size();
        if(N == 1) return nums;

        sort(nums.begin(), nums.end());
        reverse(nums.begin(), nums.end());

        // for(int ele : nums) cout<<ele<<" ";
        // cout<<"\n";

        vector<pair<int,int>>dp(N);
        for(int i=0;i<N;i++) dp[i] = make_pair(1, i);

        for(int i=0;i<N;i++) {
            for(int j=0;j<i;j++) {
                if(nums[j] % nums[i] == 0) {
                    if(dp[i].first < dp[j].first + 1) {
                        dp[i] = make_pair(dp[j].first + 1, j);
                    }
                }
            }
        }

        // for(pair<int,int>p: dp) {
        //     cout<<p.first<<" "<<p.second<<"\n";
        // }

        int maxEle = -1;
        int lstIdx = -1;

        for(int i=0;i<N;i++) {
            if(dp[i].first > maxEle) {
                maxEle = dp[i].first;
                lstIdx = i;
            }
        }

        // cout<<dp[lstIdx].first<<" "<<dp[lstIdx].second;

        vector<int>res;
        
        while(lstIdx > -1) {
            res.push_back(nums[lstIdx]);
            
            if(lstIdx == dp[lstIdx].second) break;
            
            lstIdx = dp[lstIdx].second;
        }

        return res;
    }
};