// { Driver Code Starts
#include <bits/stdc++.h>
using namespace std;


 // } Driver Code Ends
class Solution{
    public:
    //Function to find if there exists a triplet in the 
    //array A[] which sums up to X.
    bool find3Numbers(int A[], int N, int X)
    {
        //Your Code Here
        sort(A,A+N);
        
        for(int i=0;i<N-2;i++){
            int left = i + 1;
            int right= N - 1;
            
            int curr_sum = X - A[i];
            
            while(left < right){
                if(A[left] + A[right] == curr_sum) return true;
                else if(A[left] + A[right] > curr_sum) right--;
                else if(A[left] + A[right] < curr_sum) left++;
            }
        }
        
        return false;
    }

};

// { Driver Code Starts.

int main()
{
	int T;
	cin>>T;
	while(T--)
	{
		int n,X;
		cin>>n>>X;
		int i,A[n];
		for(i=0;i<n;i++)
			cin>>A[i];
		Solution ob;
        cout <<  ob.find3Numbers(A, n, X) << endl;
    }
}
  // } Driver Code Ends