#include<iostream> 
using namespace std; 

int pow(int ele,int n){
    int fact=1;
    for(int i=0;i<n;i++)fact*=ele;
    return fact;
}

int solve(int arr[],int index,int count,int &ans,int curr_cost){
    if(curr_cost>ans)
        return 0;
    if(count<=0){
        if(curr_cost<ans)
            ans=curr_cost;
    }
    int qty=pow(2,index);
    int min_rec;
    if(index>0)
        min_rec=min(solve(arr,index,count-qty,ans,curr_cost+arr[index]),solve(arr,index-1,count,ans,curr_cost));
    min_rec=solve(arr,index,count-qty,ans,curr_cost+arr[index]);
    return min_rec;
}
int birthdayPresent(int input1[],int input2,int input3){
    int ans=2147483647;
    solve(input1,input2-1,input3,ans,0);
    return ans;
}

int main() 
{
    int arr[] = {10000,1000,100,10}; 
    int n = sizeof(arr)/sizeof(arr[0]); 
  
    cout<<birthdayPresent(arr, n, 3); 
    return 0; 
} 