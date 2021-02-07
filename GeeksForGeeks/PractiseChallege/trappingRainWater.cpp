// { Driver Code Starts
#include<bits/stdc++.h>

using namespace std;

// } Driver Code Ends

// function to find the trapped water in between buildings
// arr: input array
// n: size of array

int trappingWater(int arr[], int n){
    int left=0,right=n-1;
    int ret=0;
    int leftMax=0,rightMax=0;
    
    while(left<=right){
        if(arr[left]>arr[right]){
            if(arr[right]>rightMax){
                rightMax=arr[right];
            }
            ret+=rightMax-arr[right];
            right--;
        }else{
            if(arr[left]>leftMax){
                leftMax=arr[left];
            }
            ret+=leftMax-arr[left];
            left++;
        }
    }
    
    return ret;
}


// { Driver Code Starts.

int main(){
    
    int t;
    //testcases
    cin >> t;
    
    while(t--){
        int n;
        
        //size of array
        cin >> n;
        
        int a[n];
        
        //adding elements to the array
        for(int i =0;i<n;i++){
            cin >> a[i];            
        }
        //calling trappingWater() function 
        cout << trappingWater(a, n) << endl;
        
    }
    
    return 0;
}  // } Driver Code Ends