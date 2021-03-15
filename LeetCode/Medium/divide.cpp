class Solution {
public:
    int divide(int dividend, int divisor) {
        int flag=1;
        if(dividend==0)return 0;
        if(divisor<0){
            divisor=-divisor;
            flag=-flag;
        }
        int res=0;
        while(dividend>0){
            dividend-=divisor;
            res++;
        }
        return flag*(res-1);
    }
};