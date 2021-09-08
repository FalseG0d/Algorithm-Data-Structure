// { Driver Code Starts
//Initial Template for C++

#include <bits/stdc++.h>
using namespace std;
 

 // } Driver Code Ends
//User function Template for C++

class Solution
{
    public:
    //Function to find the first position with different bits.
    int posOfRightMostDiffBit(int m, int n)
    {
        // Your code here
        int check = 1;
        int res = -1;
        
        int count = 1;
        
        while(check > 0){
            int flag = (m & check) ^ (n & check);
            
            if(flag > 0){
                res = count;
                break;
            }
            
            check <<= 1;
            count++;
        }
        
        return res;
    }
};

// { Driver Code Starts.

// Driver Code
int main()
{   
    int t;
    cin>>t; //input number of testcases
    while(t--)
    {
         int m,n;
         cin>>m>>n; //input m and n
         Solution ob;
         cout << ob.posOfRightMostDiffBit(m, n)<<endl;
    }
    return 0;     
}   // } Driver Code Ends