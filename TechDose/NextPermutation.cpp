string Solution::solve(string A) {
    int N=A.size();
    int i;

    bool flag=false;
    
    for(i=N-1;i>0;i--){
        if(A[i-1] < A[i]){
            flag=true;
            break;
            }
    }

    if(!flag) return "-1";

    sort(A.begin()+i,A.end());

    for(int j=i;j<N;j++){
        if(A[j] > A[i-1]){
            char temp = A[j];
            A[j] = A[i-1];
            A[i-1] = temp;

            break;
        }
    }

    return A;
}