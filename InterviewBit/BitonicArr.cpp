int help(vector<int> &A, int key, int beg, int end){
    if(beg > end) return -1;

    int mid = (beg + end) / 2;

    if(A[mid] == key) return mid;
    else return max(help(A,key,beg,mid - 1), help(A,key,mid+1,end));
}

int Solution::solve(vector<int> &A, int key) {
    int beg = 0;
    int end = A.size() - 1;

    return help(A,key,beg,end);
}
