class Solution {
public:
    bool isPowerOfTwo(int n) {
        if(n<=0)return false;
        
        n=n&(n-1);
        
        if(n==0)return true;
        else return false;
    }
};