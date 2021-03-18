class Solution {
public:
    vector<int> help(int n,vector<int>res){
        if(n==0){
            res.push_back(0);
            return res;
        }
        
        vector<int>ret=help(n-1,res);
        
        int count=0;
        while(n>0){
            n=n&(n-1);
            count++;
        }
        ret.push_back(count);
        
        return ret;
    }
    vector<int> countBits(int num) {
        vector<int>res;
        return help(num,res);
    }
};