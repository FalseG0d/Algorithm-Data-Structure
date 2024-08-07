class Solution {
    int**dp;
public:
    bool help(string& str, string& ptr, int itr1, int itr2) {
        if(itr1 == -1 && itr2 == -1) return true;
        if(itr2 == -1) return false;
        if(itr1 == -1) {
            // Can return true if we only have * left
            if(ptr[itr2] == '*') return help(str, ptr, itr1, itr2-2);
            return false;
        }

        // if(dp[itr1][itr2] != -1) return dp[itr1][itr2];
        
        if(str[itr1] == ptr[itr2]) return dp[itr1][itr2] = help(str, ptr, itr1-1, itr2-1);
        else if(ptr[itr2] == '.') return dp[itr1][itr2] = help(str, ptr, itr1-1, itr2-1);
        else if(ptr[itr2] == '*') {
            if(ptr[itr2-1] == str[itr1] || ptr[itr2-1] == '.') return dp[itr1][itr2] = help(str, ptr, itr1-1, itr2) || help(str, ptr, itr1-1, itr2-2) || help(str, ptr, itr1, itr2-2);
            else  return dp[itr1][itr2] = help(str, ptr, itr1, itr2-2);
        } else return dp[itr1][itr2] = false;
    }
    bool isMatch(string str, string ptr) {
        int N1 = str.length();
        int N2 = ptr.length();

        dp = new int*[N1];
        for(int i=0;i<N1;i++) dp[i] = new int[N2];

        for(int i=0;i<N1;i++) {
            for(int j=0;j<N2;j++) dp[i][j] = -1;
        }

        return help(str, ptr, N1-1, N2-1);
    }
};