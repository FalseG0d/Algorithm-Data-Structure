class Solution {
public:
    void merge(vector<int>& nums1, int m, vector<int>& nums2, int n) {
        if(n==0)return;
        
        if(m==0){
            nums1=nums2;
            return;
        }
        int itr=0;
        
        for(int i=0;i<n;i++){
            nums1[i+m]=nums2[i];
        }
        
        sort(nums1.begin(),nums1.end());
    }
};