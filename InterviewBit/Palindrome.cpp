int Solution::isPalindrome(int A) {
    int rev=0;
    int temp=A;

    while(temp>0){
        int digit=temp%10;
        rev=rev*10+digit;

        temp/=10;
    }

    return rev == A;
}