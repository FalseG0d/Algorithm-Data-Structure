#include <bits/stdc++.h>
using namespace std;

int*arr;
bool*dp;
int n;

bool targetSum(int ele){
    if(ele<0){
        return false;
    }
    if(dp[ele]){
        return true;
    }else{
        for(int i=0;i<n;i++){
            if(dp[ele])
                break;
            
            dp[ele]=dp[ele-arr[i]];
        }
        return dp[ele];
    }
}

int main(){
    int ele;
    cin>>ele;
    cin>>n;

    dp=new bool[ele+1];
    dp[0]=true;
    
    for(int i=1;i<ele+1;i++){
        dp[i]=false;
    }

    arr=new int[n];

    for(int i=0;i<n;i++){
        cin>>arr[i];
        dp[arr[i]]=true;
    }

    if(targetSum(ele)){
        cout<<"Yes";
    }else{
        cout<<"No";
    }

    return 0;
}