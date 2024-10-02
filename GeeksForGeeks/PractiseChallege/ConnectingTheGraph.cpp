//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
// User function Template for C++

class Solution {
    int available = 0;
    int required = 0;
    
    int*parent;
    int*size;
  public:
    int add(int i, int j) {
        if(i == j) {
            available++;
            return i;
        }
        
        if(parent[i] == i && parent[j] == j) {
            if(size[i] > size[j]) {
                size[i] += size[j];
                parent[j] = parent[i];
                
                return i;
            } else {
                size[j] += size[i];
                parent[i] = parent[j];
                
                return j;
            }
        }
        
        return parent[i] = parent[j] = add(parent[i], parent[j]);
    }
    int Solve(int n, vector<vector<int>>& edges) {
        // code here
        parent = new int[n];
        size = new int[n];
        
        for(int i=0;i<n;i++) parent[i] = i;
        for(int i=0;i<n;i++) size[i] = 1;
        
        // 0 0 0 0 4 5
        // 4 1 1 1 1 1
        
        for(vector<int>edge: edges) {
            add(edge[0], edge[1]);
        }
        
        // for(int i=0;i<n;i++) cout<<parent[i]<<" ";
        // cout<<"\n";
        // for(int i=0;i<n;i++) cout<<size[i]<<" ";
        // cout<<"\n";
        
        for(int i=0;i<n;i++) {
            if(parent[i] == i) required++;
        }
        
        if(required == 0) return 0;
        required--;
        
        // cout<<available<<" "<<required<<"\n";
        // return 0;
        
        return available - required >= 0 ? required : -1;
    }
};

//{ Driver Code Starts.

int main() {
    int t;
    cin >> t;
    while (t--) {
        int n, m;
        cin >> n >> m;
        vector<vector<int>> adj;

        for (int i = 0; i < m; ++i) {
            vector<int> temp;
            for (int j = 0; j < 2; ++j) {
                int x;
                cin >> x;
                temp.push_back(x);
            }
            adj.push_back(temp);
        }

        Solution Obj;
        cout << Obj.Solve(n, adj) << "\n";
    }
    return 0;
}
// } Driver Code Ends