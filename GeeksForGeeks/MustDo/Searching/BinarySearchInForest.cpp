// { Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

 // } Driver Code Ends
class Solution{
    public:
    int collectWood(int tree[], int N, int H){
        int wood = 0;
        
        for(int i=0;i<N;i++){
            if(tree[i] > H) wood += (tree[i] - H);
        }
        
        return wood;
    }
    int find_height(int tree[], int N, int K)
    {
        // code here
        int sum = 0;
        int maxH = INT_MIN;
        
        for(int i=0;i<N;i++){
            maxH = max(maxH, tree[i]);
            sum += tree[i];
        }
        
        int minH = 0;
        if(sum < K) return -1;
        
        int res = -1;
        
        while(minH <= maxH){
            int temp = minH + (maxH - minH) / 2;
            
            int collected = collectWood(tree,N,temp);
            
            // cout<<temp<<" : "<<collected<<" : "<<K<<"\n";
            
            if(collected == K){
                // cout<<"Found\n";
                res = temp;
                break;
            }
            else if(collected > K) minH = temp + 1;
            else maxH = temp - 1;
        }
        
        return res;
    }
};

// { Driver Code Starts.
int main()
{
    int t;
    cin>>t;
    while(t--)
    {
        int n,k;
        cin>>n;

        int tree[n];
        for(int i=0; i<n; i++)
            cin>>tree[i];
        cin>>k;
        Solution ob;
        cout<< ob.find_height(tree,n,k) << endl;
    }
    return 1;
}  // } Driver Code Ends