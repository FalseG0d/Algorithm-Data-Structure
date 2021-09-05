// { Driver Code Starts
//Initial Template for C++


#include<bits/stdc++.h> 
using namespace std; 


 // } Driver Code Ends
//User function Template for C++

class Solution {
public:
    void print(vector<vector<int>> hospital){
        int M = hospital.size();
        int N = hospital[0].size();
        
        for(int i=0;i<M;i++){
            for(int j=0;j<N;j++) cout<<hospital[i][j]<<" ";
            cout<<"\n";
        }
        
        cout<<"\n\n";
    }
    int dfs(vector<vector<int>> &hospital, int i, int j){
        int M = hospital.size();
        int N = hospital[0].size();
        
        if(i < 0 || j < 0 || i >= M || j >= N) return 0;
        
        if(hospital[i][j] != 1) return 0;
        
        hospital[i][j]++;
        
        int res = 0;
        
        res = max(dfs(hospital,i + 1,j), res);
        res = max(dfs(hospital,i - 1,j), res);;
        
        res = max(dfs(hospital,i,j + 1), res);
        res = max(dfs(hospital,i,j - 1), res);
        
        return res + 1;
        
    }
    int helpaterp(vector<vector<int>> hospital)
    {
        //code here
        int r = hospital.size();
        int c = hospital[0].size();
        
        queue<pair<int,int>> infected;
        for(int i = 0; i < r; i++){
            for(int j = 0; j < c; j++){
                if(hospital[i][j] == 2) infected.push(make_pair(i, j));
            }
        }
        
        int ans = -1;
        while(!infected.empty()){
            int size = infected.size();
            while(size--){
                int x = infected.front().first;
                int y = infected.front().second;
                infected.pop();
                
                hospital[x][y] = 2;
                if(x-1 >= 0 and hospital[x-1][y] == 1) infected.push(make_pair(x-1, y));
                if(x+1 < r and hospital[x+1][y] == 1) infected.push(make_pair(x+1, y));
                if(y-1 >= 0 and hospital[x][y-1] == 1) infected.push(make_pair(x, y-1));
                if(y+1 < c and hospital[x][y+1] == 1) infected.push(make_pair(x, y+1));
            }
            ans++;
        }
        
        for(int i = 0; i < r; i++){
            for(int j = 0; j < c; j++){
                if(hospital[i][j] == 1) return -1;
            }
        }
        
        return ans;
    }
};


// { Driver Code Starts.


int main()
{
    int t;
    cin >> t;
    while (t--)
    {
        int R;int C;
        
        cin>>R>>C;
        vector<vector<int>> hospital;
        int i,j;
        for(i=0;i<R;i++)
         {   vector<int> temp;
             for(j=0;j<C;j++)
            {
                int k;
                cin>>k;
                temp.push_back(k);
            }
            hospital.push_back(temp);
         }
        
        Solution ob;
        int ans = ob.helpaterp(hospital);
        cout << ans << endl;
    }
    return 0;
}  // } Driver Code Ends