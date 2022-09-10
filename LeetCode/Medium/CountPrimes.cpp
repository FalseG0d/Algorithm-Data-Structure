class Solution {
public:
    int countPrimes(int n) {
        if(n == 0 || n == 1 || n == 2) return 0;
        int res = 0;
        vector<bool>mp(n, false);
        mp[0] = mp[1] = true;
        for(long long i=2;i<n;i++){
            if(mp[i]) continue;
            
            res++;
            long long j = 0;
            for(long long j=i*i;j<n;j+=i){
                mp[j] = true;
            }
        }
        return res;
    }
};