// { Driver Code Starts
#include<bits/stdc++.h>
using namespace std;
vector<int> find(int a[], int n , int x );

int main()
{
    int t;
    cin>>t;
    while(t--)
    {
        int n,x;
        cin>>n>>x;
        int arr[n],i;
        for(i=0;i<n;i++)
        cin>>arr[i];
        vector<int> ans;
        ans=find(arr,n,x);
        cout<<ans[0]<<" "<<ans[1]<<endl;
    }
    return 0;
}


// } Driver Code Ends


vector<int> find(int arr[], int n , int x )
{
    // code here
    vector<int>ret;
    
    int beg=0;
    int end=n-1;
    int mid,res=-1;
    
    while(beg<=end){
        mid=(beg+end)/2;
        // cout<<beg<<":"<<end<<":"<<mid<<"\n";
        
        if(arr[mid]>x)end=mid-1;
        else if(arr[mid]<x)beg=mid+1;
        else{
            end=mid-1;
            res=mid;
        }
    }
    
    ret.push_back(res);
    
    beg=0;
    end=n-1;
    
    while(beg<=end){
        mid=(beg+end)/2;
        // cout<<beg<<":"<<end<<":"<<mid<<"\n";
        
        if(arr[mid]>x)end=mid-1;
        else if(arr[mid]<x)beg=mid+1;
        else{
            beg=mid+1;
            res=mid;
        }
    }
    
    ret.push_back(res);
    
    return ret;
}