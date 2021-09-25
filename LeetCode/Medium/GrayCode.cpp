class Solution {
public:
    vector<int> grayCode(int n) {
        int size = 1;
        int limit= pow(2,n);
        vector<int>res(1, 0);
        
        int itr = 0;
        
        while(size < limit){
            int curr = pow(2,itr);
            
            for(int i=size-1;i>=0;i--){
                res.push_back(res[i] + curr);
            }
            
            size *= 2;
            itr++;
        }
        
        return res;
    }
};