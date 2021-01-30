// { Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

int findLongestConseqSubseq(int arr[], int n);
 
// Driver program
int main()
{
 int  t,n,i,a[100001];
 cin>>t;
 while(t--)
 {
  cin>>n;
  for(i=0;i<n;i++)
  cin>>a[i];
  cout<<findLongestConseqSubseq(a, n)<<endl;
 }
      
    return 0;
}// } Driver Code Ends


// arr[] : the input array
// N : size of the array arr[]

// return the length of the longest subsequene of consecutive integers
int findLongestConseqSubseq(int arr[], int N)
{
  //Your code here
  set<int>s(arr,arr+N);
  int maxCount=INT_MIN,count=0;
  
  for(auto itr=s.begin();itr!=s.end();){
      int a=*itr;
      itr++;
      int b=*itr;
      
      if(a+1==b){
          count++;
      }else{
          if(count>maxCount){
              maxCount=count;
          }count=0;
      }
  }
  
  if(count>maxCount){
      maxCount=count;
  }
  
  return maxCount+1;
}