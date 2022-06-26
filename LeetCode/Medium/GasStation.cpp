class Solution {
public:
    int canCompleteCircuit(vector<int>& gas, vector<int>& cost) {
        int start = -1;
        int N = gas.size();
        
        int currDef = 0;
        int currRes = 0;
        
        vector<int>diff(N, 0);
        for(int i=0;i<N;i++){
            diff[i] = gas[i] - cost[i];
            
            currRes += diff[i];
        }
        
        if(currRes < 0) return -1;
        
        for(int i=0;i<N;i++){
            if(diff[i] >= 0){
                start = i;
                currRes = 0;
                
                while(currRes >= 0 && i < N){
                    currRes += diff[i];
                    
                    i++;
                }
                
                if(i == N){
                    if(currDef + currRes >= 0) return start;
                    
                    currDef += currRes;
                    currRes = 0;
                    
                    i--;
                    continue;
                }
                
                if(currRes < 0){
                    currDef += currRes;
                    currRes = 0;
                    
                    i--;
                    continue;
                }
            }
            
            if(i < N) currDef += diff[i];
        }
        
        return -1;
    }
};