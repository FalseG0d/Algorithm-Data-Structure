// { Driver Code Starts
//Initial template for C++

#include <bits/stdc++.h>
using namespace std;


 // } Driver Code Ends


//User function template for C++

class Solution{   
public:
    int median(vector<vector<int>> &matrix, int r, int c){
        // code here
        vector<int>v(r*c);
        
        for(int i=0;i<r;i++){
            for(int j=0;j<c;j++){
                v[i*c+j]=matrix[i][j];    
            }
        }
        
        sort(v.begin(),v.end());
        
        int mid=r*c;
        
        if(mid%2==0){
            return (v[mid/2]+v[mid/2-1])/2;
        }else{
            return v[mid/2];
        }
    }
};

// { Driver Code Starts.

int main()
{
    int t;
    cin>>t;
    while(t--)
    {
        int r, c;
        cin>>r>>c;
        vector<vector<int>> matrix(r, vector<int>(c));
        for(int i = 0; i < r; ++i)
            for(int j = 0;j < c; ++j)
                cin>>matrix[i][j];
        Solution obj;
        cout<<obj.median(matrix, r, c)<<endl;        
    }
    return 0;
}  // } Driver Code Ends