class Solution {
public:
    string longestCommonSubsequence(string text1, string text2) {
        int N1 = text1.length();
        int N2 = text2.length();

        int**dp = new int*[N1+1];

        for(int i=0;i<N1+1;i++) dp[i] = new int[N2+1];

        for(int i=0;i<=N1;i++) dp[i][0] = 0;
        for(int j=0;j<=N2;j++) dp[0][j] = 0;

        for(int i=1;i<=N1;i++) {
            for(int j=1;j<=N2;j++) {
                if(text1[i-1] == text2[j-1]) dp[i][j] = 1 + dp[i-1][j-1];
                else dp[i][j] = max(dp[i-1][j], dp[i][j-1]);
            }
        }

        string res = "";

        int i=N1;
        int j=N2;

        while(i > 0 && j > 0) {
            if(text1[i-1] == text2[j-1]) {
                res = text1[i-1] + res;
                i--;j--;
                }
            else {
                if(dp[i-1][j] > dp[i][j-1]) i--;
                else j--;
            }
        }

        return res;
    }
    string shortestCommonSupersequence(string str1, string str2) {
        string lcs = longestCommonSubsequence(str1, str2);      

        int itr1 = 0;
        int itr2 = 0;
        int itr3 = 0;

        int N1 = str1.length();
        int N2 = str2.length();
        int N3 = lcs.length();

        string res = "";

        while(itr1 < N1 && itr2 < N2 && itr3 < N3) {
            if(str1[itr1] == str2[itr2] && str2[itr2] == lcs[itr3]) {
                res += lcs[itr3];
                
                itr1++;
                itr2++;
                itr3++;
            } else if(str2[itr2] == lcs[itr3]) {
                res += str1[itr1];

                itr1++;
            } else {
                res += str2[itr2];

                itr2++;
            }
        }

        while(itr1 < N1) {
            res += str1[itr1];
            itr1++;
        }

        while(itr2 < N2) {
            res += str2[itr2];
            itr2++;
        }

        return res;
    }
};