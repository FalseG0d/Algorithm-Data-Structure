// { Driver Code Starts
#include<bits/stdc++.h>
using namespace std;


 // } Driver Code Ends
class Solution{
public:
    string swap(string a,char first,char secon){
        int N = a.length();
        
        for(int i=0;i<N;i++){
            if(a[i] == first) a[i] = secon;
            else if(a[i] == secon) a[i] = first;
        }
        
        return a;
    }
    string chooseandswap(string a){
        // Code Here
        int map[26];
        memset(map,-1,sizeof(map));
        
        int N = a.length();
        
        for(int i=0;i<N;i++){
            if(map[a[i] - 'a'] == -1) map[a[i] - 'a'] = i;
        }
        
        char first;
        char secon;
        
        for(int i=0;i<N;i++){
            first = a[i];
            secon = a[i];
            
            
            for(int j=0;j<a[i] - 'a';j++){
                if(map[j] > i){
                    secon = j + 'a';
                    return swap(a,first,secon);
                }
            }
        }
        
        return a;
    }
    
};


// { Driver Code Starts.

int main()
{
    Solution obj;
	int t;
	cin >> t;
	while(t--)
	{	
	    string a;
		cin >> a;
		cout << obj.chooseandswap(a) << endl;
	}
	return 0;
}
  // } Driver Code Ends