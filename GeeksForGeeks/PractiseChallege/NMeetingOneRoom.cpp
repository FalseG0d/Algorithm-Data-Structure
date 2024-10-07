//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
class Solution {
  public:
    // Function to find the maximum number of meetings that can
    // be performed in a meeting room.
    int maxMeetings(int n, int start[], int end[]) {
        
        vector<pair<int,int>> ans;
        
        for(int i =0;i<n;i++)
        {
            ans.push_back({end[i],start[i]});
        }
        
        sort(ans.begin(),ans.end());
        
        int lastEle = 0;
        int count = 0;
        
        for(auto num:ans)
        {
            if(num.second > lastEle)
            {
                count++;
                lastEle = num.first;
            }
        }
        
        return count;
    }
};

//{ Driver Code Starts.
int main() {
    int t;
    cin >> t;
    while (t--) {
        int n;
        cin >> n;
        int start[n], end[n];
        for (int i = 0; i < n; i++)
            cin >> start[i];

        for (int i = 0; i < n; i++)
            cin >> end[i];

        Solution ob;
        int ans = ob.maxMeetings(n, start, end);
        cout << ans << endl;
    }
    return 0;
}
// } Driver Code Ends