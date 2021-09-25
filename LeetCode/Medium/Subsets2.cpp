class Solution {
public:
    
//     struct comparator{
//         bool operator()(const vector<int>&v1,const vector<int>&v2) const{
//             int s1 = 0;
//             int s2 = 0;

//             int multi = 1;

//             for(int ele : v1){
//                 s1 += ele * multi;
//                 multi *= 10;
//             }

//             multi = 1;

//             for(int ele : v2){
//                 s2 += ele * multi;
//                 multi*=10;
//             }

//             return s1 < s2;
//         }
//     };
    
    vector<vector<int>> subsetsWithDup(vector<int>& nums) {
        vector<vector<int>> tmpRes;
        vector<int>temp;
        
        sort(nums.begin(),nums.end());
        
        tmpRes.push_back(temp);
        
        for(int ele : nums){
            int n = tmpRes.size();
            for(int i=0;i<n;i++){
                tmpRes[i].push_back(ele);
                
                tmpRes.push_back(tmpRes[i]);
                
                tmpRes[i].pop_back();
            }
        }
        
        set<vector<int>>res(tmpRes.begin(), tmpRes.end());
        return vector<vector<int>>(res.begin(),res.end());
    }
};