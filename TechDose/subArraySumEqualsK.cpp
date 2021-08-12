class Solution {
public:
    int subarraySum(vector<int>& V, int S) {
        int N=V.size();
        
        map<int,int>mp;
        int res=0;
        
        int currSum=0;
        
        for(int i=0;i<N;i++){
            currSum+=V[i];
            
            if(currSum == S) res++;
            if(mp.find(currSum-S)!=mp.end()) res+=mp[currSum-S];
            
            mp[currSum]++;
        }
        
        return res;
    }
};