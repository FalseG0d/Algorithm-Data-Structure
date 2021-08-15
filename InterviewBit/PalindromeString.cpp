int Solution::isPalindrome(string A) {
    int N=A.length();
    if(N == 1) return true;
    
    int beg=0;
    int end=N-1;

    while(beg<=end){
        while(!isalnum(A[beg]) && beg < end) beg++;
        while(!isalnum(A[end]) && beg < end) end--;

        // cout<<A[beg]<<":"<<A[end]<<"\n";
        if(beg == end) break;

        if(tolower(A[beg]) != tolower(A[end])) return false;

        beg++;
        end--;
    }

    return true;
}