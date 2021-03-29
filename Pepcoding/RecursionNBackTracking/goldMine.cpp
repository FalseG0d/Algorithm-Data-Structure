#include<bits/stdc++.h>
using namespace std;

int goldMine(int arr[10][10],int m,int n,int p,int q,int sum){
    if(p<0||p>=m||q<0||q>=n)return sum;
    if(arr[p][q]==0)return sum;
    
    sum+=arr[p][q];

    int val=arr[p][q];
    arr[p][q]=0;
    
    int s=-1;
    
    s=max(s,goldMine(arr,m,n,p+1,q,sum));
    s=max(s,goldMine(arr,m,n,p-1,q,sum));
    s=max(s,goldMine(arr,m,n,p,q+1,sum));
    s=max(s,goldMine(arr,m,n,p,q-1,sum));
    
    arr[p][q]=val;

    return s;
}

int main(){
    int m,n;
    cin>>m>>n;
    
    int arr[10][10];
    
    for(int i=0;i<m;i++){
        for(int j=0;j<n;j++){
            cin>>arr[i][j];
        }
    }
    
    int res=-1;
    
    for(int i=0;i<m;i++){
        for(int j=0;j<n;j++)res=max(res,goldMine(arr,m,n,i,j,0));
    }

    cout<<res;

    return 0;
}