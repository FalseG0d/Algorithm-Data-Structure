class NumArray {
public:
    vector<int> arr;
    NumArray(vector<int>& nums) {
        arr.push_back(0);
        arr.push_back(nums[0]);
        
        int N = nums.size();
        
        for(int i=1;i<N;i++) arr.push_back(nums[i] + arr[i]);
        
        for(int ele : arr) cout<<ele<<" ";
    }
    
    int sumRange(int left, int right) {
        return arr[right + 1] - arr[left];
    }
};

/**
 * Your NumArray object will be instantiated and called as such:
 * NumArray* obj = new NumArray(nums);
 * int param_1 = obj->sumRange(left,right);
 */