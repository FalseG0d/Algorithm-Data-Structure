// { Driver Code Starts
#include<bits/stdc++.h>

using namespace std;


 // } Driver Code Ends


class Solution{

    // Function to find the trapped water between the blocks.
    public:
    vector<int>maxToRight(int arr[],int n){
        vector<int>res;
        stack<int>s;
    
        for(int i=n-1;i>=0;i--){
            if(s.empty()){
                res.push_back(-1);
                s.push(arr[i]);
            }else{
                while(!s.empty()){
                    if(s.top()<=arr[i])
                        s.pop();
                    else
                        break;
                }
                if(s.empty()){
                    res.push_back(-1);
                    s.push(arr[i]);
                }else{
                    res.push_back(s.top());
                }
    
            }
        }
        
        reverse(res.begin(),res.end());
    
        return res;
    }
    vector<int>maxToLeft(int arr[],int n){
        vector<int>res;
        stack<int>s;
    
        for(int i=0;i<n;i++){
            if(s.empty()){
                res.push_back(-1);
                s.push(arr[i]);
            }else{
                while(!s.empty()){
                    if(s.top()<=arr[i])
                        s.pop();
                    else
                        break;
                }
                if(s.empty()){
                    res.push_back(-1);
                    s.push(arr[i]);
                }else{
                    res.push_back(s.top());
                }
    
            }
        }
    
        return res;
    }
    int trappingWater(int arr[], int n){
        // Code here
        vector<int>left=maxToLeft(arr,n);
        vector<int>right=maxToRight(arr,n);
        
        // for(int i=0;i<n;i++)cout<<left[i]<<"\t";
        // cout<<"\n";
        // for(int i=0;i<n;i++)cout<<right[i]<<"\t";
        // cout<<"\n";
        // for(int i=0;i<n;i++)cout<<arr[i]<<"\t";
        // cout<<"\n";
        int res=0;
        
        for(int i=0;i<n;i++){
            if(left[i]!=-1&&right[i]!=-1){
                int height=min(left[i],right[i]);
                res+=height-arr[i];
            }
        }
        
        return res;
    }
};

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
        Solution obj;
        //calling trappingWater() function
        cout << obj.trappingWater(a, n) << endl;
        
    }
    
    return 0;
}  // } Driver Code Ends