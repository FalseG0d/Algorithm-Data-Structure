class Solution{
    int**dp;
public:
    int solve(int arr[], int beg, int end)
    {
        if(beg >= end) return 0;
        if(dp[beg][end] != -1) return dp[beg][end];
        
        int res = INT_MAX;
        
        for(int k=beg;k<end;k++) {
            res = min(res, solve(arr, beg, k) + solve(arr, k+1, end) + arr[beg-1] * arr[k] * arr[end]);
        }
        
        return dp[beg][end] = res;
    }
    int matrixMultiplication(int N, int arr[])
    {
        // code here
        dp = new int*[N];
        for(int i=0;i<N;i++) dp[i] = new int[N];
        
        for(int i=0;i<N;i++) {
            for(int j=0;j<N;j++) dp[i][j] = -1;
        }
        
        for(int i=0;i<N;i++) dp[i][i] = 0;
        
        return solve(arr, 1, N-1);
    }
};