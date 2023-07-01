class Solution {
public:
    vector<int> bruteTwoSum(vector<int>& nums, int target) {
        vector<int> temp;
        
        for(int i=0;i<nums.size()-1;i++){
            for(int j=i+1;j<nums.size();j++){
                if(nums[i]+nums[j]==target){
                    temp.push_back(i);
                    temp.push_back(j);
                    
                    cout<<i<<" "<<j;
                    break;
                }
            }
        }
        
        return temp;
    }
	vector<int> optimizedTwoSum(vector<int>& nums, int target) {
        map<int,int> maps;
        vector<int> temp;
        for(int i=0;i<nums.size();i++){
            maps[nums[i]]=i;
        }
        for(int i=0;i<nums.size();i++){
            int complement=target-nums[i];
            if(maps[complement]&&maps[complement]!=i){
                temp.push_back(i);
                temp.push_back(maps[complement]);
                return temp;
            }
        }
    return temp;
    }
};