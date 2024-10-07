//{ Driver Code Starts
// Program to find the maximum profit job sequence from a given array 
// of jobs with deadlines and profits 
#include<bits/stdc++.h>
using namespace std; 

// A structure to represent a job 
struct Job 
{ 
    int id;	 // Job Id 
    int dead; // Deadline of job 
    int profit; // Profit if job is over before or on deadline 
}; 


// } Driver Code Ends
/*
struct Job 
{ 
    int id;	 // Job Id 
    int dead; // Deadline of job 
    int profit; // Profit if job is over before or on deadline 
};
*/

class Solution 
{
    public:
    static bool compare(Job ele1, Job ele2) {
        return ele2.profit < ele1.profit;
    }
    //Function to find the maximum profit and the number of jobs done.
    vector<int> JobScheduling(Job arr[], int n) 
    { 
        // your code here
        sort(arr, arr+n, compare);
        int deadline = 0;
        for(int i=0;i<n;i++) deadline = max(deadline, arr[i].dead);
        
        bool*schedule = new bool[deadline];
        for(int i=0;i<deadline;i++) schedule[i] = true;
        
        int profit = 0;
        int count = 0;
        
        for(int i=0;i<n;i++) {
            int time = arr[i].dead - 1;
            
            while(time >= 0 && !schedule[time]) time--;
            
            if(time >= 0 && schedule[time]) {
                schedule[time] = false;
                count++;
                profit += arr[i].profit;
            }
        }
        
        return {count, profit};
    } 
};

//{ Driver Code Starts.
// Driver program to test methods 
int main() 
{ 
    int t;
    //testcases
    cin >> t;
    
    while(t--){
        int n;
        
        //size of array
        cin >> n;
        Job arr[n];
        
        //adding id, deadline, profit
        for(int i = 0;i<n;i++){
                int x, y, z;
                cin >> x >> y >> z;
                arr[i].id = x;
                arr[i].dead = y;
                arr[i].profit = z;
        }
        Solution ob;
        //function call
        vector<int> ans = ob.JobScheduling(arr, n);
        cout<<ans[0]<<" "<<ans[1]<<endl;
    }
	return 0; 
}



// } Driver Code Ends