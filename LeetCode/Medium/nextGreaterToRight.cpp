class Solution {
public:
    vector<int> nextGreaterElement(vector<int>& nums1, vector<int>& nums2) {
        int N1 = nums1.size() - 1;
        int N2 = nums2.size() - 1;

        stack<int>st;
        vector<int>greaterToRight(N2+1, 0);

        for(int i=N2;i>=0;i--) {
            greaterToRight[i] = -1;
            
            while(!st.empty()) {
                int top = st.top();

                if(top > nums2[i]) {
                    greaterToRight[i] = top;
                    break;
                    }
                else st.pop();
            }

            st.push(nums2[i]);
        }

        unordered_map<int,int>mp;
        vector<int>res(N1+1, 0);

        for(int i=0;i<=N2;i++) mp[nums2[i]] = greaterToRight[i];
        for(int i=0;i<=N1;i++) res[i] = mp[nums1[i]];

        return res;
    }
};