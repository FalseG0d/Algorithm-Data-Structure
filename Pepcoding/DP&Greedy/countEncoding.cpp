#include <bits/stdc++.h>
using namespace std;

bool valid(char tens,char ones){
    string str="";
    str+=tens;
    str+=ones;

    stringstream conv(str);
    int x=0;

    conv>>x;
    // cout<<x<<",";

    return x<=26 && x>=1;
}

int main() {
    string str;
    cin>>str;

    int n=str.length();
    
    int*dp=new int[n+1];
    for(int i=0;i<n+1;i++) dp[i]=0;

    if(n>0) dp[1]=1;

    for(int i=2;i<n+1;i++){
        if(str[i-1]!='0') dp[i]+=dp[i-1];
        if(valid(str[i-2],str[i-1])) dp[i]+=i-2>0?dp[i-2]:1;
    }

    // cout<<"\n";
    // for(int i=0;i<n+1;i++) cout<<dp[i]<<" ";

    cout<<dp[n];

    return 0;
}
