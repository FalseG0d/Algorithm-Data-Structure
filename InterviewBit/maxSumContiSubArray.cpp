int Solution::maxSubArray(const vector<int> &A) {
    int n = A.size();
    if(n==0) return 0;
    // if(n==1) return A[0];

    int sum = A[0];
    int sumSoFar=0;
    
    for(int i=0;i<n;i++){
        sumSoFar+=A[i];

        
        if(sumSoFar>sum) sum=sumSoFar;
        if(sumSoFar<0) sumSoFar=0;
    }

    return sum;
}