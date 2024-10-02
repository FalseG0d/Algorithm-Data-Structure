//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
//User function Template for C++

class Solution {
    int*parent;
    int*size;
  public:
    int add(int i, int j) {
        if(i == j) return i;
        else if(parent[i] == i && parent[j] == j) {
            if(size[i] > size[j]) {
                parent[j] = i;
                size[i] += size[j];
                
                return i;
            } else {
                parent[i] = j;
                size[j] += size[i];
                
                return j;
            }
        }
        
        return parent[j] = parent[i] = add(parent[i], parent[j]);
    }
    
    int numProvinces(vector<vector<int>> adj, int V) {
        // code here
        parent = new int[V];
        size = new int[V];
        
        for(int i=0;i<V;i++) parent[i] = i;
        for(int i=0;i<V;i++) size[i] = 1;
        
        for(int i=0;i<V;i++) {
            for(int j=0;j<V;j++) {
                if(i == j) continue;
                if(adj[i][j] == 1) {
                    add(i, j);
                }
            }
        }
        
        // for(int i=0;i<V;i++) {
        //     cout<<parent[i]<<" ";
        // }
        // cout<<"\n";
        // for(int i=0;i<V;i++) {
        //     cout<<size[i]<<" ";
        // }
        // cout<<"\n";
        
        int res = 0;
        
        for(int i=0;i<V;i++) {
            if(parent[i] == i) res++;
        }
        
        return res;
    }
};

//{ Driver Code Starts.

int main() {
    int t;
    cin >> t;
    while (t--) {
        int V,x;
        cin>>V;
        
        vector<vector<int>> adj;
        
        for(int i=0; i<V; i++)
        {
            vector<int> temp;
            for(int j=0; j<V; j++)
            {
                cin>>x;
                temp.push_back(x);
            }
            adj.push_back(temp);
        }
        

        Solution ob;
        cout << ob.numProvinces(adj,V) << endl;
    }
    return 0;
}
// } Driver Code Ends