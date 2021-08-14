public class Solution {
    public int reverse(int A) {
        boolean neg_Num=false;

        if(A < 0){
            neg_Num = true;
            A=-A;
            }

        int rev_num=0;
        int pre_num=0;

        while(A!=0){
            int digit = A % 10;
            rev_num = rev_num * 10 + digit;

            if((rev_num - digit)/10 != pre_num) return 0;

            pre_num = rev_num;
            A/=10;
        }

        return neg_Num?-rev_num:rev_num;
    }
}