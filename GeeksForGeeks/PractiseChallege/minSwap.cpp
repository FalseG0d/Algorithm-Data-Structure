// { Driver Code Starts
// C++ program to find minimum swaps required
// to club all elements less than or equals
// to k together
#include <iostream>
using namespace std;


int minSwap(int *arr, int n, int k);

// Driver code
int main() {

	int t,n,k;
	cin>>t;
	while(t--)
    {
        cin>>n;
        int arr[n];
        for(int i=0;i<n;i++)
            cin>>arr[i];
        cin>>k;
        cout << minSwap(arr, n, k) << "\n";
    }
	return 0;
}
// } Driver Code Ends


int minSwap(int *arr, int n, int k) {
    int cnt=0;
    int res=100000;
    
    for(int i=0;i<n;i++){
        if(arr[i]<=k)
            cnt++;
    }
    
    int same=0;
    int diff=0;
    
    for(int i=0;i<cnt&&i<n;i++){
        if(arr[i]<=k)
            same++;
        else
            diff++;
    }
    
    if(diff==0)
        return 0;
    
    int i=cnt;
    res=min(res,diff);
    
    while(i<n){
        if(arr[i-cnt]>k){
            diff--;
        }else{
            same--;
        }
        
        if(arr[i]>k)
            diff++;
        else
            same--;
            
        res=min(res,diff);
        i++;
    }
    
    return res;
}
