int Solution::solve(vector<int> &A, int B) {
    int N = A.size();
    unordered_map<int,int>mp;
    mp[0] = 1;
    
    int res = 0;
    
    for(int i=1;i<N;i++) A[i] = A[i] ^ A[i-1];
    
    for(int i=0;i<N;i++) {
        res += mp[A[i] ^ B];
        
        mp[A[i]]++;
    }
    
    return res;
}
