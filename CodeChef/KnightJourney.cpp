#include <bits/stdc++.h>
using namespace std;

int count(int**dp, int x1, int y1, int x2, int y2){
    if(x1 >= 8 || x1 < 0 || x2 >= 8 || x2 < 0 || y1 >= 8 || y1 < 0 || y2 >= 8 || y2 < 0) return 1000;
    if(x1 == x2 && y1 == y2) return 0;
    if(dp[x1][y1] == 0) return 1000;
    if(dp[x1][y1] != -1) return dp[x1][y1];

    dp[x1][y1] = 0;

    int res = INT_MAX;
    
    res = min(res, count(dp, x1+1, y1+2, x2, y2));
    res = min(res, count(dp, x1-1, y1+2, x2, y2));
    res = min(res, count(dp, x1+1, y1-2, x2, y2));
    res = min(res, count(dp, x1-1, y1-2, x2, y2));
    
    res = min(res, count(dp, x1+2, y1+1, x2, y2));
    res = min(res, count(dp, x1-2, y1+1, x2, y2));
    res = min(res, count(dp, x1+2, y1-1, x2, y2));
    res = min(res, count(dp, x1-2, y1-1, x2, y2));

    return dp[x1][y1] = 1 + res;
}

int main() {
    int T;
    cin>>T;

    while(T--){
        int **dp = new int*[8];
        for(int i=0;i<8;i++) dp[i] = new int[8]{-1, -1, -1, -1, -1, -1, -1, -1};

        int x1, y1, x2, y2;

        cin>>x1>>y1>>x2>>y2;

        int res = count(dp, x1-1, y1-1, x2-1, y2-1);
        
        if(res > 100) cout<<"NO\n";
        else{
            if((100 - res) % 2 == 0) cout<<"YES\n";
            else cout<<"NO\n";
            }
    }
    
    return 0;
}
