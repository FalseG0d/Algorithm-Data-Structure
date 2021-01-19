// { Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

 // } Driver Code Ends


//User function template for C++
class Solution{
public:
    static void rRotate(int arr[],int n,int pos){
        for(int i=n-1;i>pos;i--){
            arr[i]=arr[i-1];
        }
    }
    static void lRotate(int arr[],int n,int pos){
        for(int i=pos;i<n;i++){
            arr[i]=arr[i+1];
        }
    }
	void merge(int arr1[], int arr2[], int n, int m) {
	    // code here
	    for(int i=0;i<n;i++){
	        for(int j=0;j<m;j++){
	            if(arr1[i]>arr2[j]){
	                int temp=arr1[i];
	                arr1[i]=arr2[j];
	                arr2[j]=temp;
	            }
	        }
	    }
	}
};

// { Driver Code Starts.
int main() {
    int t;
    cin >> t;
    while (t--) {
        int n, m, i;
        cin >> n >> m;
        int arr1[n], arr2[m];
        for (i = 0; i < n; i++) {
            cin >> arr1[i];
        }
        for (i = 0; i < m; i++) {
            cin >> arr2[i];
        }
        Solution ob;
        ob.merge(arr1, arr2, n, m);
        for (i = 0; i < n; i++) {
            cout << arr1[i] << " ";
        }
        for (i = 0; i < m; i++) {
            cout << arr2[i] << " ";
        }
        cout << "\n";
    }
    return 0;
}  // } Driver Code Ends