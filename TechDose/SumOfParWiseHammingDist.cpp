int Solution::hammingDistance(const vector<int> &A) {
    long long int N=A.size();
    long long int res=0;

    for(int i=0;i<31;i++){
        long long int countOfOne=0;
        for(int j=0;j<N;j++){
            if(A[j] & 1<<i) countOfOne++;
        }

        res += countOfOne*(N-countOfOne);
    }

    return (2 * res)%1000000007;
}
