class Solution {
public:
    int*dp;
    int help(string s, int i) {
        int len = s.length();
        
        if(i >= len) return 1;
        if(dp[i] != -1) return dp[i];
        
        if(s[i] == '0') return dp[i] = 0;
        if(len - i == 0 || len - i == 1) return dp[i] = 1;
        
        string str = s.substr(i,2);
        // cout<<str[0]<<", "<<str<<"\n";
        
        if(str <= "26") return dp[i] = help(s, i+1) + help(s, i+2);
        else return dp[i] = help(s, i+1);
    }
    int numDecodings(string s) {
        int len = s.length();
        dp = new int[len];
        
        for(int i=0;i<len;i++) dp[i] = -1;
        
        return help(s,0);
    }
};