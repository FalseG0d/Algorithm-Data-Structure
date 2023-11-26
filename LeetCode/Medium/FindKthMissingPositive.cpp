class Solution {
public:
    int findKthPositive(vector<int>& arr, int k) {
        // for(int ele : arr) cout<<ele<<" ";
        // cout<<"\n";
        int N = arr.size();
        int itr = 0;
        int val = 1;

        while(itr < N) {
            // cout<<arr[itr]<<" "<<val<<", ";
            if(val == arr[itr]) itr++;
            else {
                k--;
                
                if(k == 0) break;
                }

            val++;
        }

        if(k > 0) return val + k - 1;

        return val;
    }
};