// { Driver Code Starts
#include<bits/stdc++.h>
using namespace std;
int longestSubstrDistinctChars (string S);
int main()
{
    int t; cin >> t;
    while (t--)
    {
        string S; cin >> S;

        cout << longestSubstrDistinctChars (S) << endl;
    }
}

// Contributed By: Pranay Bansal
// } Driver Code Ends


int longestSubstrDistinctChars (string S)
{
    // your code here
    int N = S.length();
    
    int mp[256];
    memset(mp,-1,sizeof(int)*256);
    
    int prev[N];
    memset(prev,-1,sizeof(int)*N);
    
    
    int ans  = -1;
    int temp = 0;
    
    for(int i=0;i<N;i++){
        if(mp[S[i]] == -1){
            mp[S[i]] = i;
            prev[i]  = -1;
        }else{
            prev[i]  = mp[S[i]];
            mp[S[i]] = i;
        }
    }
    
    // for(int i=0;i<N;i++){
    //     cout<<i<<"\t";
    // }cout<<"\n";
    
    // for(int i=0;i<N;i++){
    //     cout<<S[i]<<"\t";
    // }cout<<"\n";
    
    // for(int i=0;i<N;i++){
    //     cout<<prev[i]<<"\t";
    // }cout<<"\n";
    
    memset(mp,0,sizeof(int)*256);
    
    for(int i=0;i<N;i++){
        if(mp[S[i]] > 0){
            ans = max(ans,temp);
            
            // cout<<i<<":"<<i-temp<<"\n";
            
            i = prev[i];
            temp=0;
            memset(mp,0,sizeof(int)*256);
        }else{
            mp[S[i]]++;
            temp++;
        }
    }
    
    return max(ans,temp);
}