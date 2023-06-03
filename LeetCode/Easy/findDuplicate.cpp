class Solution {
public:
    int findDuplicate(vector<int>& nums) {
        map<int,int> m;
        
        for(int i=0;i<nums.size();i++){
            if(m.find(nums[i])!=m.end()){
                m[nums[i]]=0;
            }else{
                m[nums[i]]+=1;
            }
        }
        map<int,int>::iterator itr;
        
        for(itr=m.begin();itr!=m.end();++itr){
            if(itr->second!=1){
                return itr->first;
                
            }
        }
        
        // for(itr=m.begin();itr!=m.end();++itr){
        //     cout<<itr->first<<":"<<itr->second<<"\n";
        // }
        
        return -1;
    }
};