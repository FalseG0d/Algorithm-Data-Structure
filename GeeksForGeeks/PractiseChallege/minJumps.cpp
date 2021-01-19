// { Driver Code Starts
#include<bits/stdc++.h>
using namespace std;


 // } Driver Code Ends


int countJumps(int arr[],int n,int pos){
    cout<<pos<<":"<<arr[pos]<<"\n";
    if(pos>=n-1){
        return 0;
    }
    if(pos+arr[pos]>=n-1){
        return 1;
    }
    
    int jumps=arr[pos];
    int minJump=INT_MAX;
    
    for(int i=jumps;i>0;i--){
        minJump=min(countJumps(arr,n,pos+i),minJump);
    }
    
    return minJump+1;
}

// Function to return minimum number of jumps to end of array
int minJumps(int arr[], int n){
    // Your code here
    return countJumps(arr,n,0);
}



// { Driver Code Starts.

int main()
{
    int t;
    cin>>t;
    while(t--)
    {
        int n,i,j;
        cin>>n;
        int arr[n];
        for(int i=0; i<n; i++)
            cin>>arr[i];
            
        cout<<minJumps(arr, n)<<endl;
    }
    return 0;
}
  // } Driver Code Ends