// { Driver Code Starts
#include <bits/stdc++.h>
using namespace std;


 // } Driver Code Ends


// function to find the triplet which sum to x
// arr[] : The input Array
// N : Size of the Array
// X : Sum which you need to search for 

bool find3Numbers(int arr[], int N, int X)
{
    //Your Code Here
    set<int>m(arr,arr+N);
    
    // for(auto itr=m.begin();itr!=m.end();++itr){
    //     cout<<*itr<<" ";
    // }cout<<"\n";
    
    for(int i=0;i<N-1;i++){
        int sum=arr[i];
        for(int j=i+1;j<N;j++){
            int key=X-(sum+arr[j]);
            if(m.find(key)!=m.end()){
                if(key!=arr[i]&&key!=arr[j])
                    return true; 
            }
        }
    }
    return false;
}


// { Driver Code Starts.

int main()
{
	int T;
	cin>>T;
	while(T--)
	{
		int N,sum;
		cin>>N>>sum;
		int i,A[N];
		for(i=0;i<N;i++)
			cin>>A[i];
        cout <<  find3Numbers(A, N, sum) << endl;
    }
}
  // } Driver Code Ends