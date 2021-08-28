class Solution {
public:
    string shortestCommonSupersequence(string str1, string str2) {
        int X = str1.length();
        int Y = str2.length();
        
        int**dp = new int*[X + 1];
        for(int i=0;i<X+1;i++) dp[i] = new int[Y+1];
        
        for(int i=0;i<X+1;i++){
            for(int j=0;j<Y+1;j++){
                if(i == 0 || j == 0) dp[i][j] = 0;
                else if(str1[i - 1] == str2[j - 1]) dp[i][j] = 1 + dp[i - 1][j - 1];
                else dp[i][j] = max(dp[i - 1][j], dp[i][j - 1]);
            }
        }
        
        int i = X;
        int j = Y;
        
        string lcs = "";
        
        while(i > 0 && j > 0){
            if(str1[i - 1] == str2[j - 1]){
                i--;
                j--;
                
                lcs = str1[i] + lcs;
            }else{
                if(dp[i][j - 1] > dp[i - 1][j]){
                    j--;
                    lcs = str2[j] + lcs;
                }
                else{
                    i--;
                    lcs = str1[i] + lcs;
                }
            }
        }
        
        while(j>0){
            j--;
            lcs = str2[j] + lcs;
        }
        
        while(i>0){
            i--;
            lcs = str1[i] + lcs;
        }
        
        return lcs;
    }
};