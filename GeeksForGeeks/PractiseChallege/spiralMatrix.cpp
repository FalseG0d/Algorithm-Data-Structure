// { Driver Code Starts
#include <bits/stdc++.h> 
using namespace std; 

 // } Driver Code Ends


class Solution
{   
public:     
    vector<int> spirallyTraverse(vector<vector<int>> matrix, int r, int c) 
    {
        // code here
        vector<int>v;
        // int lim1=r-1,lim2=c-1;
        
        for(int p=0;p<c;p++)
        {
            for(int i=p;i<c-p;i++){
                v.push_back(matrix[p][i]);
            }
            for(int i=p+1;i<r-p;i++){
                v.push_back(matrix[i][c-p-1]);
            }
            for(int i=c-p-2;i>=p;i--){
                v.push_back(matrix[c-p-1][i]);
            }
            for(int i=r-p-2;i>p;i--){
                v.push_back(matrix[i][p]);
            }
        }
        
        return v;
    }
};

// { Driver Code Starts.
int main() {
    int t;
    cin>>t;
    
    while(t--) 
    {
        int r,c;
        cin>>r>>c;
        vector<vector<int> > matrix(r); 

        for(int i=0; i<r; i++)
        {
            matrix[i].assign(c, 0);
            for( int j=0; j<c; j++)
            {
                cin>>matrix[i][j];
            }
        }

        Solution ob;
        vector<int> result = ob.spirallyTraverse(matrix, r, c);
        for (int i = 0; i < result.size(); ++i)
                cout<<result[i]<<" ";
        cout<<endl;
    }
    return 0;
}  // } Driver Code Ends