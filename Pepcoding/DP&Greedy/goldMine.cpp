#include<iostream>
using namespace std;

int n,m;
int**arr;

int**dp;

const int INT_MIN=-2147483648;

int max(int a,int b,int c){
    if(a>b){
        if(a>c) return a;
        else return c;
    }else{
        if(b>c) return b;
        else return c;
    }
}

int maxGold(int i,int j){
    if(i>=n||i<0||j>=m) return 0;
    if(dp[i][j]!=-1) return dp[i][j];

    int up=maxGold(i-1,j+1);
    int straight=maxGold(i,j+1);
    int down=maxGold(i+1,j+1);
    
    return dp[i][j]=arr[i][j]+max(up,down,straight);
}

int main(){
    cin>>n>>m;
    arr=new int*[n];
    for(int i=0;i<n;i++) arr[i]=new int[m];
    
    for(int i=0;i<n;i++){
        for(int j=0;j<m;j++) cin>>arr[i][j];
    }

    dp=new int*[n];
    for(int i=0;i<n;i++) dp[i]=new int[m];
    
    for(int i=0;i<n;i++){
        for(int j=0;j<m;j++) dp[i][j]=-1;
    }
    
    int max=INT_MIN;
    for(int i=0;i<n;i++){
        int temp=maxGold(i,0);
        max=max>temp?max:temp;

        // cout<<i+1<<":"<<temp<<"\n";
    }
    
    cout<<max;
    
    return 0;
}