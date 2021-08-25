// { Driver Code Starts
#include<bits/stdc++.h> 
using namespace std; 

 // } Driver Code Ends
class Solution{   
public:
    int maximumSumSubarray(int K, vector<int> &Arr , int N){
        // code here 
        int temp = 0;
        int i=0;
        int j=0;
        
        while(i<K){
            temp += Arr[i];
            i++;
        }
        
        int maxSum = temp;
        
        while(i<N){
            temp -= Arr[j];
            temp += Arr[i];
            maxSum = max(maxSum,temp);
            
            j++;
            i++;
        }
        
        return maxSum;
    }
};

// { Driver Code Starts.
int main() 
{ 
    int t;
    cin>>t;
    while(t--)
    {
        int N,K;
        cin >> N >> K;;
        vector<int>Arr;
        for(int i=0;i<N;++i){
            int x;
            cin>>x;
            Arr.push_back(x);
        }
        Solution ob;
        cout << ob.maximumSumSubarray(K,Arr,N) << endl;
    }
    return 0; 
}   // } Driver Code Ends