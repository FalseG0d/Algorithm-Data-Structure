// { Driver Code Starts
#include<bits/stdc++.h>
using namespace std;

 // } Driver Code Ends
class Solution{
	public:
	string fractionToDecimal(int numerator, int denominator) {
        string ans = "";
        
        int remain_index;
        ans = ans + to_string(numerator/denominator);
        
        int remain = numerator % denominator;
        
        if(remain != 0)
        {
            ans += ".";
        }
        
        unordered_map<int,int> mp;
        
        int len = ans.size();
        
        while(remain != 0 && mp.find(remain) == mp.end())
        {
            mp[remain] = len;
            numerator = remain * 10;
            ans = ans + to_string(numerator/denominator);
            remain = numerator % denominator;
            len = len+1;
        }
        
        if(remain != 0)
        {
            remain_index = mp[remain];
            ans = ans.substr(0,remain_index)+"("+ans.substr(remain_index,ans.size()-remain_index+1)+")";
        }
        
        return ans;
    
    }

};

// { Driver Code Starts.
int main(){
	int tc;
	cin >> tc;
	while(tc--){
		int numerator, denominator;
		cin >> numerator >> denominator;
		Solution ob;
		string ans = ob.fractionToDecimal(numerator, denominator);
		cout << ans <<"\n";
	}
	return 0;
}  // } Driver Code Ends