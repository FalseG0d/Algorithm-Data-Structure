//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

struct Item{
    int value;
    int weight;
};


// } Driver Code Ends
//class implemented
/*
struct Item{
    int value;
    int weight;
};
*/


class Solution
{
    public:
    //Function to get the maximum total value in the knapsack.
    double fractionalKnapsack(int W, Item arr[], int n)
    {
        // Your code here
        priority_queue<pair<double,int>> pq;
        
        for(int i=0;i<n;i++){
            Item temp = arr[i];
            
            pq.push(make_pair((double)temp.value/temp.weight, temp.weight));
        }
        
        double res = 0;
        
        while(!pq.empty() && W > 0){
            pair<double,int>temp = pq.top();
            pq.pop();
            
            if(W - temp.second >= 0){
                res += (temp.first * temp.second);
                W -= temp.second;
            }else{
                res += (temp.first * W);
                W = 0;
            }
        }
        
        return res;
    }
        
};


//{ Driver Code Starts.
int main()
{
	int t;
	//taking testcases
	cin>>t;
	cout<<setprecision(2)<<fixed;
	while(t--){
	    //size of array and weight
		
        int n, W;
		cin>>n>>W;
		
		Item arr[n];
		//value and weight of each item
		for(int i=0;i<n;i++){
			cin>>arr[i].value>>arr[i].weight;
		}
		
		//function call
		Solution ob;
		cout<<ob.fractionalKnapsack(W, arr, n)<<endl;
	}
    return 0;
}
// } Driver Code Ends