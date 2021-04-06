#include <iostream>
using namespace std;

int*arr;

int cs(int n){
    // write your code here
    if(n==0)return 1;
    if(n<0)return 0;
    if(arr[n]!=-1)return arr[n];
    
    arr[n]=cs(n-3)+cs(n-2)+cs(n-1);
    
    return arr[n];

}

int main(){
    int n;
    cin>>n;
    
    arr=new int[n+1];
    for(int i=0;i<n+1;i++)arr[i]=-1;
    arr[0]=1;
    
    cout<<cs(n)<<endl;
}