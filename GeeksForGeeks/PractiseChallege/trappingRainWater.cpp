// { Driver Code Starts
#include<bits/stdc++.h>

using namespace std;


 // } Driver Code Ends


   

// function to find the trapped water in between buildings
// arr: input array
// n: size of array
int trappingWater(int arr[], int n){
    // Your code here
    int*temp=arr;
    set<int>s(arr,arr+n);
    auto itr=s.end();
    --itr;
    --itr;
    int height=*itr;
    
    int sum=0;
    for(int i=0;i<n;i++){
        int level=height-temp[i];
        
        if(level>0&&){
            sum+=level;
        }
    }
    
    return sum;
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