class Solution {
public:
    int rangeBitwiseAnd(int left, int right) {
        vector<int>res(32);
        for(int i=0;i<32;i++) res[i] = 1;
        
        int ret = 0;
        
        for(int i=0;i<32;i++){
            long long check = 1;
            check = check<<i;

            for(long long j=left;j<=right;j++){
                check = check & j;

                if(check == 0){
                    res[i] = 0;
                    break;
                    }
                }
            
            ret += res[i] << i;
        }
        
        return ret;
    }
};